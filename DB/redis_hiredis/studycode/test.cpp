#include <unistd.h>
#include <string.h>
#include <getopt.h>
#include <hiredis/hiredis.h>

#define MAX_KEY_LEN 11
typedef struct t_key_table1 {
    int  dummykey1;
    char key1[MAX_KEY_LEN] key1;
    char key2[MAX_KEY_LEN] key1;
} t_key_table1;


typedef enum {
    OPER_ADD    = 0,
    OPER_DEL    = 1
}OPER_TYPE;

/* Table1's entry content */
#define MAX_NAME_LEN 11
typedef struct T_EntryT1Content
{
    char name[MAX_NAME_LEN];
} T_EntryT1Content;

static const int DB1 = 1;
static redisContext *ctx = NULL;
static char def_key1 = {0x30,0x31,0x32,0x33,0};
static char def_key2 = {0x41,0x42,0x43,0x44,0};

static int
initRedisContext()
{
    redisReply *reply;
    int rc = 0;

    ctx = redisConnect("localhost", 6379);
    if (ctx == NULL)
    {
        printf("Failed to create redisContext");
        rc = -1;
    }
    else if (ctx->err)
    {
        printf("Couldn't connect to redis at %s:%d (%s)", "localhost", 6379, ctx->errstr ? ctx->errstr : "unknown");
        redisFree(ctx);
        ctx = NULL;
        rc = -1;
    }

    /* select DB1 for this context */
    reply = (redisReply*)redisCommand(ctx, "SELECT %d", DB1);
    if (ctx->err)
    {
        printf("Error selecting database %d (%s)\n", DB1,
               ctx->errstr ? ctx->errstr : "unknown");
        rc = -1;
    }

    return rc;
}

/* make redis key and store in input buffer */
static int
makeRedisKey(t_key_table1* key, char* rediskey)
{
    if (!key || !rediskey)
    {
        return -1;
    }

    sprintf(rediskey, "%02x-%02x%02x%02x%02x%02x%02x-%02x%02x%02x%02x%02x%02x",
            key->dummykey1,
            key->key2[0],
            key->key2[1],
            key->key2[2],
            key->key2[3],
            key->key2[4],
            key->key2[5],
            key->key1[0],
            key->key1[1],
            key->key1[2],
            key->key1[3],
            key->key1[4],
            key->key1[5]);

    return 0;
}

void
printentryEntryT1(T_EntryT1Content* pEntryT1)
{
    if (pEntryT1)
    {
        fprintf(stdout, "EntryT1's name = %02x:%02x:%02x:%02x:%02x:%02x\n",
                pEntryT1->name[0],
                pEntryT1->name[1],
                pEntryT1->name[2],
                pEntryT1->name[3],
                pEntryT1->name[4],
                pEntryT1->name[5]);
        return;
    }
}

static int
addentryEntryT1(t_key_table1* key, T_EntryT1Content* pEntryT1)
{
    char tmpkey[64];
    redisReply *reply;
    int rc = -1;
    time_t ex = time(NULL) + 300; /* expiry 300s from now, use lease time later */

    /* initialize context if not already done */
    if (ctx == NULL)
    {
        if ((initRedisContext() != 0) || (ctx == NULL))
        {
            return rc;
        }
    }

    makeRedisKey(key, tmpkey);
    reply = (redisReply*)redisCommand(ctx, "SET %s %b EXAT %lld", tmpkey, pEntryT1, sizeof(T_EntryT1Content), ex);
    if (ctx->err)
    {
        printf("Error sending redis command (%s)\n", ctx->errstr ? ctx->errstr : "unknown");
    }
    else
    {
        if ((reply->type == REDIS_REPLY_STATUS) && (strncmp(reply->str, "OK", 2) == 0))
            rc = 0;
    }
    freeReplyObject(reply);

    return rc;
}

static int
deleteentryEntryT1(char* key)
{
    redisReply *reply;
    int rc = -1;

    if (key == NULL)
    {
        return -1;
    }

    /* initialize context if not already done */
    if (ctx == NULL)
    {
        if ((initRedisContext() != 0) || (ctx == NULL))
        {
            return rc;
        }
    }

    reply = (redisReply*)redisCommand(ctx, "DEL %s", key);
    if (ctx->err)
    {
        printf("Error sending redis command (%s)\n", ctx->errstr ? ctx->errstr : "unknown");
    }
    else if ((reply->type == REDIS_REPLY_INTEGER) && (reply->integer == 1))
    {
        rc = 0;
    }
    freeReplyObject(reply);

    return rc;
}

static int
getentryEntryT1(char* key, T_EntryT1Content* pEntryT1)
{
    redisReply *reply;
    int rc = -1;

    /* initialize context if not already done */
    if (ctx == NULL)
    {
        if ((initRedisContext() != 0) || (ctx == NULL))
        {
            return rc;
        }
    }

    reply = (redisReply*)redisCommand(ctx, "GET %s", key);
    if (ctx->err)
    {
        printf("Error sending redis command (%s)\n", ctx->errstr ? ctx->errstr : "unknown");
    }
    else
    {
        /* reply should be binary string of the entry info */
        if (reply->type == REDIS_REPLY_STRING)
        {
            /* check size in case it's changed in newer sw version */
            size_t size = reply->len <= sizeof(T_EntryT1Content) ?
                reply->len : sizeof(T_EntryT1Content);
            memcpy(pEntryT1, reply->str, size);
            rc = 0;
        }
    }
    freeReplyObject(reply);

    return rc;
}

int
DBentryoper(t_key_table1* key, T_EntryT1Content* pEntryT1, OPER_TYPE oper)
{
    int rc = 0;

    switch(oper)
    {
        case OPER_ADD:
        {
            /* add entry entry, redis will overwrite if already exists */
            if ((rc = addentryEntryT1(key, pEntryT1)) != 0)
            {
                printf("Error addentryEntryT1\n");
            }
            break;
        }
        case OPER_DEL:
        {
            char key[64];
            makeRedisKey(key, key);
            rc = deleteentryEntryT1(key);
            break;
        }
        default:
        {
        }
    }

    return rc;
}

static int
createEntries(void)
{
    t_key_table1 key;
    T_EntryT1Content entry;

    memcpy(key.key1, def_key1, sizeof(def_key1));
    memcpy(key.key2, def_key2, sizeof(def_key2));
    key.dummykey1 = 1;
    for (int i = 0; i < 100; i++)
    {
        key.key1[5] = i;
        key.key2[5] = i;
        memcpy(entry.name, key.key2, sizeof(char));
        DBentryoper(&key, &entry, OPER_ADD);
    }

    return 0;
}

static int
deleteAllEntries(void)
{
    int rc = 0;
    redisReply *reply;
    char *key;
    T_EntryT1Content pEntryT1;

     /* initialize context if not already done */
    if (ctx == NULL)
    {
        if ((initRedisContext() != 0) || (ctx == NULL))
        {
            return 1;
        }
    }

    reply = (redisReply*)redisCommand(ctx, "KEYS *");
    /* expect array of sub-replies in reply, each sub-reply is of
       string type with str contains the key */
    if ((reply->type != REDIS_REPLY_ARRAY) || !(reply->elements > 0))
    {
        fprintf(stdout, "No entries found\n");
        rc = 1;
    }

    fprintf(stdout, "Remove all %d entry entries from database:\n", (int)reply->elements);
    for (int i = 0; i < reply->elements; i++)
    {
        key = reply->element[i]->str;
        if ((rc = deleteentryEntryT1(key)) == 0)
        {
            fprintf(stdout, "Removed entry %s\n", key);
        }
        else
        {
            break;
        }
    }
    freeReplyObject(reply);

    return rc;
}

static int
dumpEntries(void)
{
    int rc = 0;
    redisReply *reply;
    char *key;
    T_EntryT1Content pEntryT1;

     /* initialize context if not already done */
    if (ctx == NULL)
    {
        if ((initRedisContext() != 0) || (ctx == NULL))
        {
            return 1;
        }
    }

    reply = (redisReply*)redisCommand(ctx, "KEYS *");
    /* expect array of sub-replies in reply, each sub-reply is of
       string type with str contains the key */
    if ((reply->type != REDIS_REPLY_ARRAY) || !(reply->elements > 0))
    {
        fprintf(stdout, "No entries found\n");
        rc = 1;
    }
    else
    {
        fprintf(stdout, "All %d entry entries in database:\n", (int)reply->elements);
        for (int i = 0; i < reply->elements; i++)
        {
            key = reply->element[i]->str;
            if ((rc = getentryEntryT1(key, &pEntryT1)) == 0)
            {
                printentryEntryT1(&pEntryT1);
            }
            else
            {
                break;
            }
        }
    }
    freeReplyObject(reply);

    return rc;
}

static void
usage(char *pn)
{
    fprintf(stderr, "Usage: %s [-s] [-d]\n"
            "   -c --create\n"
            "        create DB with a set of entries\n"
            "   -d --delete\n"
            "        Remove all entries\n"
            "   -p --print\n"
            "        print all entry entries\n", basename(pn));
}

int
main(int argc, char **argv)
{
    int rc = 1;
    int c, option_index;
    const char *short_options = "pcd";
    const struct option long_options[] = {
        {"create",  no_argument,          0,    'c'},
        {"delete",  no_argument,          0,    'd'},
        {"print",   no_argument,          0,    'p'},
        {0,         0,                    0,    0},
    };

    if (argc < 2)
    {
        usage(argv[0]);

        return 1;
    }

    if (initRedisContext() != 0)
    {
        printf("Error initializing redis context\n");
        return -1;
    }

    c = getopt_long(argc, argv, short_options, long_options, &option_index);
    switch (c)
    {
        case 'c':
        {
            rc = createEntries();
            break;
        }
        case 'd':
        {
            rc = deleteAllEntries();
            break;
        }
        case 'p':
        {
            rc = dumpEntries();
            break;
        }
        default:
            usage(argv[0]);
    }

    if (ctx != NULL)
    {
        redisFree(ctx);
    }

    return rc;
}
