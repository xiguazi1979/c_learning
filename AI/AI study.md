# snake
请提供一个C语言源代码，在ubuntu上可以编译运行一个贪吃蛇游戏
gcc snake.c -o snake.exe -lncurses
./snake.exe

# 模型训练计划
一、前期准备（Win11环境配置）
1. 安装基础工具
(1) Python 环境

    推荐 Python 3.10（兼容性最好）

    下载地址：Python 官网

    安装时勾选 "Add Python to PATH"（方便命令行调用）

    验证安装：
    bash

    python --version
    pip --version

(2) CUDA & cuDNN（GPU加速）

    RTX 3060 12GB 支持 CUDA 11.8 或 CUDA 12.x

    安装步骤：

        下载 NVIDIA CUDA Toolkit（推荐 CUDA 11.8）
        → CUDA Toolkit 11.8

        安装时选择 自定义安装，确保勾选 CUDA Development Tools

        下载 cuDNN（需注册 NVIDIA 账号）
        → cuDNN 8.6.0 for CUDA 11.x

        解压 cuDNN，复制 bin、include、lib 到 C:\Program Files\NVIDIA GPU Computing Toolkit\CUDA\v11.8

        验证安装：
        bash

        nvcc --version  # 应显示 CUDA 11.8
        nvidia-smi      # 检查 GPU 是否识别

(3) Git（代码管理）

    下载地址：Git for Windows

    安装后验证：
    bash

    git --version

2. 安装深度学习框架
(1) PyTorch（推荐）

    运行以下命令安装 PyTorch + CUDA 11.8：
    bash

pip install torch torchvision torchaudio --index-url https://download.pytorch.org/whl/cu118

验证 GPU 是否可用：
python

    import torch
    print(torch.cuda.is_available())  # 应返回 True
    print(torch.cuda.get_device_name(0))  # 应显示 "RTX 3060"

(2) Hugging Face Transformers（大模型必备）
bash

pip install transformers datasets accelerate bitsandbytes peft

(3) 其他实用工具
bash

pip install jupyterlab langchain sentencepiece tiktoken

二、本地运行大模型（适合 RTX 3060 12GB）
1. 运行量化模型（4bit/8bit）
(1) 使用 text-generation-webui（可视化界面）

    适合 7B/13B 量化模型（ChatGLM3、Qwen1.5、Mistral）

    安装：
    bash

git clone https://github.com/oobabooga/text-generation-webui
cd text-generation-webui
pip install -r requirements.txt

下载 4bit 量化模型（如 Qwen1.5-7B-Chat-GPTQ）：
bash

python download-model.py Qwen/Qwen1.5-7B-Chat-GPTQ

启动：
bash

    python server.py --model Qwen1.5-7B-Chat-GPTQ --listen --auto-devices

    访问 http://localhost:7860 进行交互

(2) 使用 Ollama（命令行运行）

    适合 快速测试 Llama3、Mistral 等

    安装：
    bash

curl -fsSL https://ollama.com/install.sh | sh

运行 7B 量化模型：
bash

    ollama pull mistral:7b-instruct-q4_0
    ollama run mistral:7b-instruct-q4_0

三、推荐学习教程（适合 Win11 + RTX 3060）
1. 入门级（零基础）
教程	链接	特点
微软 AI 大模型通识课（中文）	GitHub	零基础入门，涵盖 LLM 基础、API 使用
Happy-LLM（Datawhale）	GitHub	系统性学习，适合中文用户
B 站：大模型课程 L1-1	Bilibili	暨南大学课程，理论+实践
2. 实战级（微调/部署）
教程	链接	特点
LLM-Universe（Datawhale）	GitHub	从零构建知识库助手
Ollama 微调指南	Collabnix	本地微调 Llama3/Mistral
LangChain 实战	LangChain Crash Course	构建 AI Agent
四、后续学习路径

    基础掌握后 → 学习 LoRA/QLoRA 微调（适合 7B 模型）

    进阶 → 尝试 RAG（检索增强生成），如 LangChain + FAISS

    生产级 → 学习 Docker 部署，如 FastAPI + vLLM

总结

✅ 已完成：

    安装 Python + CUDA + PyTorch

    配置 Hugging Face 环境

    运行本地 7B 量化模型（Qwen/Mistral）

📚 推荐学习：

    新手 → 微软 AI 大模型通识课

    实战 → LLM-Universe

    微调 → Ollama 微调指南

你的 RTX 3060 12GB 完全可以胜任 7B 模型的推理和轻量微调，按这个路线逐步深入即可！
