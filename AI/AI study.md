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


# WSL2平台训练计划
配置：R54600G, 16GX2 DDR4, 256G NVME, 3060 12G, 长城电源额定750W, 可追加机械硬盘1T或SSD 512G, 目前win11，如需要可改装linux
辅助学习配置笔记本（在另一个时间段可以使用）：13th Gen Intel(R) Core(TM) i5-1340P (1.90 GHz)， 16G RAM, 200G空闲磁盘NVME

以下是针对你的需求优化的 Win11 + WSL2 大模型学习计划，结合性能限制分析及对应解决方案，帮助你在WSL2环境下高效学习：
一、WSL2 的优势与适用场景
1. 优势

    接近原生Linux体验：支持大多数Linux工具链（如Bash、Docker）26

    GPU加速支持：可通过CUDA on WSL调用NVIDIA显卡（RTX 3060 12GB可用）47

    开发便利性：

        直接在Windows文件系统（如/mnt/c/）访问数据

        无缝使用VS Code远程开发（Remote-WSL扩展）

2. 适用场景

    轻量级训练/推理（7B以下量化模型）

    快速实验原型开发

    学习Linux环境但不装双系统

二、WSL2 的限制与解决方案
1. 性能损失（对比纯Linux）
问题	影响	解决方案
I/O 速度较慢	数据集加载延迟（尤其小文件）	将数据放在WSL2内部文件系统（如~/data），而非Windows挂载盘（/mnt/c/）4
GPU穿透开销	训练速度比纯Linux慢5-15%	使用--gpus all确保GPU直通，并关闭Windows后台进程（如Defender）7
CUDA库兼容性问题	部分库（如cuDNN）需手动配置路径	在~/.bashrc添加：export LD_LIBRARY_PATH=/usr/lib/wsl/lib:$LD_LIBRARY_PATH5
内存管理不足	大模型可能触发OOM（如13B+）	限制WSL2内存：在%USERPROFILE%\.wslconfig设置memory=12GB（留余量给Windows）9
2. 功能限制
问题	替代方案
无法直接使用NVIDIA工具（如nsight）	通过Windows原生工具（如NVIDIA-SMI）监控GPU状态
多GPU训练支持差	仅单GPU可用，分布式训练需纯Linux或云服务器
Docker性能较低	使用nvidia-docker而非Windows Docker Desktop
三、优化后的 WSL2 学习计划
阶段1：环境配置（1天）

    启用WSL2并安装Ubuntu 22.04
    powershell

wsl --install -d Ubuntu-22.04
wsl --set-version Ubuntu-22.04 2

配置CUDA on WSL

    安装Windows版NVIDIA驱动（官网下载）

    在WSL2内安装CUDA Toolkit：
    bash

    sudo apt install nvidia-cuda-toolkit
    nvidia-smi  # 验证GPU识别

优化WSL2设置
创建%USERPROFILE%\.wslconfig：
ini

    [wsl2]
    memory=12GB  # 限制内存，避免OOM
    processors=6  # 分配6核（R5 5500X3D共6核）

阶段2：模型运行（3-5天）
推荐工具
工具	用途	优化技巧
text-generation-webui	本地对话模型（7B/13B量化）	使用--auto-devices --gpu-memory 10限制显存占用15
Ollama	快速运行Llama3/Mistral	ollama pull mistral:7b-instruct-q4_0（4bit量化版）
vLLM	高性能推理引擎	仅限Linux原生，WSL2性能损失约10%4
关键命令示例
bash

#在WSL2中运行量化模型（示例：Qwen1.5-7B）
python -m transformers.run_generation \
    --model Qwen/Qwen1.5-7B-Chat \
    --load-in-4bit \
    --device cuda \
    --trust-remote-code

阶段3：轻量微调（5-7天）
适用技术

    LoRA/QLoRA（显存占用<10GB）
    python

    from peft import LoraConfig
    config = LoraConfig(r=8, target_modules=["q_proj", "v_proj"])  # 低秩适配

    数据集优化

        预处理数据放在WSL2内部（~/datasets）加速读取

        使用datasets库流式加载（避免全量加载）

避坑指南

    避免使用Model.fit()（可能卡死），改用自定义训练循环1

    监控显存：
    bash

    watch -n 1 nvidia-smi  # 实时查看GPU使用

四、何时应切换回纯Windows？
建议纯Windows的场景

    使用Windows专属工具（如Unity ML-Agents）

    调试GUI应用（如PyQt5可视化）

    运行ONNX/DirectML加速的模型（如Stable Diffusion）

建议纯Linux的场景

    大规模训练（13B+全参数微调）

    多GPU/分布式训练

    生产环境部署

五、学习资源推荐（WSL2适配版）

    微软官方WSL2+CUDA指南：链接

    Hugging Face课程（WSL2兼容）：链接

    WSL2性能优化技巧：CSDN博客10

总结

✅ WSL2适合你当前需求（7B模型学习+轻量微调），但需注意：

    I/O性能需优化（数据放WSL2内部）

    GPU穿透有轻微损耗（约5-15%）

    内存需手动限制（防OOM）

若后续进阶到大规模训练，建议过渡到Ubuntu物理机/云服务器。


# WSL2 AI环境搭建指南 - 1 day then ask what are these terms used.

## 硬件配置
- **笔记本**：13th Gen Intel i5-1340P, 16GB RAM, 200GB NVME (核显)
- **台式机**：R5 4600G, 32GB DDR4, RTX 3060 12GB, 256GB NVME + 可扩展存储

## 第一阶段：WSL2安装与配置

### 步骤1：安装WSL2
```powershell
# 检查WSL状态
wsl --list --verbose

步骤1：以管理员身份打开PowerShell

    按下 Win + X，选择 终端(管理员) 或 Windows PowerShell(管理员)

    确保不是普通CMD（必须管理员权限）
# 1. 启用WSL功能（如果之前没做过）
dism.exe /online /enable-feature /featurename:Microsoft-Windows-Subsystem-Linux /all /norestart

# 2. 启用虚拟机平台（关键步骤！）
dism.exe /online /enable-feature /featurename:VirtualMachinePlatform /all /norestart

# 3. 设置WSL2为默认版本
wsl --set-default-version 2
# 重启系统（必须）
# 重启后继续下一步

方法1：通过微软商店安装（推荐）

    打开 Microsoft Store（微软商店）

    搜索 "Ubuntu 22.04 LTS"

    点击 "获取" → "安装"
方法2：
    wsl --install -d Ubuntu-22.04
```

### 步骤2：Ubuntu初始设置
```bash
首次启动Ubuntu

    在 开始菜单 找到并点击 Ubuntu 22.04
    （首次启动会显示控制台窗口，等待解压完成）

    设置 用户名 和 密码：

        用户名建议全英文（如llmuser）

        密码输入时不会显示字符，正常输入后回车确认
        （密码用于sudo操作，建议简单易记如123456）

# 更新系统
sudo apt update && sudo apt upgrade -y

# 安装基础工具
sudo apt install -y wget curl git vim htop
sudo apt install -y make g++ git
sudo apt install -y cmake build-essential git python3-pip

文件互访：
win: \\wsl.localhost\
linux: cd /mnt/c/
```

cursor/vscode win11远程访问wsl2：
搜索并安装以下两个核心插件：

    Remote - WSL（微软官方开发，必装）

    WSL（Cursor 增强支持，可选但推荐）
左下角可以点击然后选择wsl来链接

阶段1：环境配置
所有设备通用步骤：

    打开 Cursor → 确保左下角显示 WSL: Ubuntu-22.04

    在 Cursor 的 WSL 终端中执行：
    bash

sudo apt update
sudo apt install -y python3-venv git
mkdir -p ~/llm_env && cd ~/llm_env
python3 -m venv venv
source venv/bin/activate

### 步骤3 python3环境
阶段2：安装依赖
笔记本（无显卡）：
bash

#安装CPU专用库
pip install torch torchvision torchaudio --index-url https://download.pytorch.org/whl/cpu
pip install transformers sentencepiece accelerate

家里台式机（RTX 3060）：
bash

#安装GPU加速版（必须严格匹配你的CUDA版本！）
pip install torch torchvision torchaudio --index-url https://download.pytorch.org/whl/cu118  # CUDA 11.8
pip install transformers accelerate bitsandbytes
#验证GPU是否可用
python -c "import torch; print(torch.cuda.is_available())"

### 模型推理实验
阶段1：下载模型
#1. 安装 Git LFS
sudo apt-get update
sudo apt-get install -y git-lfs
git lfs install

笔记本（无显卡） → 选择 TinyLlama-1.1B（4bit量化）：
bash

cd ~/llm_env
git lfs install
git clone https://huggingface.co/TheBloke/TinyLlama-1.1B-Chat-v1.0-GGUF #如果下载不了，用下面的：
git clone https://hf-mirror.com/TheBloke/TinyLlama-1.1B-Chat-v1.0-GGUF
wget https://hf-mirror.com/TheBloke/TinyLlama-1.1B-Chat-v1.0-GGUF/resolve/main/tinyllama-1.1b-chat-v1.0.Q4_K_M.gguf #这个最快

家里台式机（RTX 3060） → 选择 Qwen1.5-7B（4bit量化）：
bash

cd ~/llm_env
git lfs install
git clone https://huggingface.co/Qwen/Qwen1.5-7B-Chat-GPTQ


阶段2：准备运行环境 和 启动推理
步骤1：进入模型目录
bash

cd TinyLlama-1.1B-Chat-v1.0-GGUF

步骤2：安装必要工具
sudo apt-get update && sudo apt-get install -y libopenblas-dev
sudo apt-get install pkg-config
如果是 CPU 环境（笔记本无显卡）：
bash

#安装 llama.cpp（优化CPU推理）
source venv/bin/activate
git clone https://github.com/ggerganov/llama.cpp
cd llama.cpp
make -j4  # 编译（-j4表示用4个CPU核心加速）



cd ~/llm_env/llama.cpp
rm -rf build
#禁用CURL功能（如果不需要从网络直接加载模型）
cmake -B build -DCMAKE_BUILD_TYPE=Release -DLLAMA_CURL=OFF -DGGML_BLAS=ON -DGGML_BLAS_VENDOR=OpenBLAS
#确保安装CURL后重新配置
#cmake .. -DLLAMA_CURL=ON
cmake --build build --config Release -j $(nproc)
ls -lh bin/main 


如果是 GPU 环境（家里台式机 RTX 3060）：
bash

pip install transformers accelerate sentencepiece  # 已安装可跳过

步骤3：运行模型
CPU 版（笔记本）：
bash

#回到模型目录
cd ~/llm_env/TinyLlama-1.1B-Chat-v1.0-GGUF
如果是wget的:
./bin/main -m ../tinyllama-1.1b-chat-v1.0.Q4_K_M.gguf -p "你好"

#使用 llama.cpp 运行（示例指令）
../llama.cpp/main -m tinyllama-1.1b-chat-v1.0.Q4_K_M.gguf \
  -p "你好，请介绍一下你自己" \
  -n 128  # 生成128个token

cd /home/www/llm_env
./llama.cpp/build/bin/llama-cli -m tinyllama-1.1b-chat-v1.0.Q4_K_M.gguf
what is 1+1?

GPU 版（台式机）：
python

#在Cursor中新建Python文件（如run.py）
from transformers import AutoModelForCausalLM, AutoTokenizer

model = AutoModelForCausalLM.from_pretrained(
    "./TinyLlama-1.1B-Chat-v1.0-GGUF",
    device_map="auto"
)
tokenizer = AutoTokenizer.from_pretrained("./TinyLlama-1.1B-Chat-v1.0-GGUF")

inputs = tokenizer("你好，请介绍一下你自己", return_tensors="pt").to("cuda")
outputs = model.generate(**inputs, max_new_tokens=128)
print(tokenizer.decode(outputs[0]))

步骤4：验证输出

    预期结果：模型会生成类似以下的回复：
    text

你好！我是一个TinyLlama-1.1B人工智能助手，擅长回答一般性问题...