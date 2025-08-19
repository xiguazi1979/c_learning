from transformers import AutoModelForCausalLM, AutoTokenizer, BitsAndBytesConfig
import torch
import re

# 优化量化配置
quantization_config = BitsAndBytesConfig(
    load_in_4bit=True,
    bnb_4bit_compute_dtype=torch.float16,
    bnb_4bit_quant_type="nf4",
    bnb_4bit_use_double_quant=False,
)

print("正在加载模型，请稍候...")

# 加载本地模型
model = AutoModelForCausalLM.from_pretrained(
    "./Qwen1.5-7B-Chat",
    quantization_config=quantization_config,
    device_map="auto",
    trust_remote_code=True
)
tokenizer = AutoTokenizer.from_pretrained(
    "./Qwen1.5-7B-Chat",
    trust_remote_code=True
)

# 确保tokenizer有pad token
if tokenizer.pad_token is None:
    tokenizer.pad_token = tokenizer.eos_token

print("模型加载完成！")
print("开始对话（输入 'quit' 或 'exit' 退出）")
print("-" * 60)

def generate_response(prompt):
    """生成回复的函数"""
    print("正在处理您的输入...")
    
    messages = [
        {"role": "system", "content": "你是一个专业的写作助手，请根据用户提供的材料和要求进行写作。完成后就停止。"},
        {"role": "user", "content": prompt}
    ]
    
    # 使用chat template
    text = tokenizer.apply_chat_template(
        messages,
        tokenize=False,
        add_generation_prompt=True
    )
    
    # 编码输入
    model_inputs = tokenizer(
        text, 
        return_tensors="pt", 
        padding=True,
        truncation=True,
        max_length=2048,
    ).to(model.device)

    input_token_count = model_inputs.input_ids.shape[1]
    print(f"输入token数量: {input_token_count}")
    
    # 生成响应 - 添加停止条件
    generated_ids = model.generate(
        **model_inputs,
        max_new_tokens=1200,  # 限制最大长度
        temperature=0.7,
        top_p=0.9,
        do_sample=True,
        pad_token_id=tokenizer.pad_token_id,
        eos_token_id=tokenizer.eos_token_id,
        repetition_penalty=1.15,  # 增加重复惩罚
        no_repeat_ngram_size=3,   # 防止3-gram重复
        stopping_criteria=None,    # 清除之前的停止条件
    )

    # 提取新生成的token
    generated_ids = generated_ids[:, input_token_count:]
    
    response = tokenizer.decode(generated_ids[0], skip_special_tokens=True)
    
    # 清理响应 - 移除可能的重复内容
    response = clean_response(response)
    
    return response

def clean_response(text):
    """清理响应文本，移除重复和无关内容"""
    # 移除开头的重复提示
    text = re.sub(r'^(当然|好的|明白了|接下来|那么|首先|现在)', '', text)
    
    # 移除过多的换行
    text = re.sub(r'\n\s*\n\s*\n+', '\n\n', text)
    
    # 截断到合理的长度
    if len(text) > 2000:
        # 找到最后一个完整的句子结束
        last_period = text[:1500].rfind('。')
        last_question = text[:1500].rfind('？')
        last_exclamation = text[:1500].rfind('！')
        
        end_pos = max(last_period, last_question, last_exclamation)
        if end_pos > 0:
            text = text[:end_pos + 1]
    
    return text.strip()

def get_complete_input():
    """获取完整的输入"""
    print("\n请输入您的问题或要求：")
    print("提示：可以粘贴多行文本，输入空行结束")
    
    content = []
    while True:
        try:
            line = input()
            if line.strip() == '' and content:  # 有内容后空行结束
                break
            if line.strip():  # 只添加非空行
                content.append(line)
        except EOFError:
            break
        except KeyboardInterrupt:
            print("\n输入中断")
            return None
    
    return '\n'.join(content)

# 命令行交互循环
while True:
    try:
        user_input = get_complete_input()
        
        if user_input is None:
            continue
            
        # 检查退出条件
        if user_input.lower() in ['quit', 'exit', 'q']:
            print("再见！")
            break
            
        # 处理空输入
        if not user_input.strip():
            print("请输入有效的内容")
            continue
        
        print("AI 正在生成回答..." + " " * 20, end="\r", flush=True)
        
        # 生成并输出回复
        response = generate_response(user_input)
        
        # 显示输出
        print("\n" + "=" * 80)
        print("AI 生成的回答:")
        print("=" * 80)
        print(response)
        print("=" * 80)
        print(f"回答长度: {len(response)} 字符")
        
        # 询问是否继续
        print("\n" + "-" * 40)
        continue_input = input("是否继续？(y/n, 默认y): ").strip().lower()
        if continue_input in ['n', 'no', 'quit', 'exit']:
            print("再见！")
            break
            
    except KeyboardInterrupt:
        print("\n\n程序被用户中断，再见！")
        break
    except Exception as e:
        print(f"\n发生错误: {e}")
        print("请重新输入")