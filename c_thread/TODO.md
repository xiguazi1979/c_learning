pthread_mutex_t efmoam_mgntthread_startup_lock = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t efmoam_prtclthread_ready_cond = PTHREAD_COND_INITIALIZER;
bool efmoam_prtclthread_ready_flag = false;

// 线程A的函数
void* threadA_function(void* arg) {
    // 进入主循环前，等待来自threadB的通知
    pthread_mutex_lock(&efmoam_mgntthread_startup_lock);
    while (!efmoam_prtclthread_ready_flag) {
        pthread_cond_wait(&efmoam_prtclthread_ready_cond, &efmoam_mgntthread_startup_lock);
    }

    pthread_mutex_unlock(&efmoam_mgntthread_startup_lock);

    // 执行主循环
    for (int i = 0; i < 5; ++i) {
        printf("Thread A is running main loop iteration %d\n", i);
        sleep(1); // 模拟工作
    }

    return NULL;
}

// 线程B的函数
void* threadB_function(void* arg) {
    // 模拟一些工作
    sleep(2);

    // 在进入主循环之前，通知threadA
    pthread_mutex_lock(&efmoam_mgntthread_startup_lock);
	efmoam_prtclthread_ready_flag = true;
    pthread_cond_signal(&efmoam_prtclthread_ready_cond); // 发送信号
    pthread_mutex_unlock(&efmoam_mgntthread_startup_lock);