Cursor官方文档
https://docs.cursor.com/zh/welcome

## 多个chat (CTRL+T)
## 调出几天前chat的历史 (ALT+CTRL+')
## chat内容导出为markdown (chat右上角三个点)
## @-符号
提供明确上下文最简单的方法是使用@-符号。
@code   @file   @folder
@Docs doc_filename
@Web ask string what to be searched on line for latest info

## 规则
你应该将规则视为长期记忆，供你或团队其他成员访问。捕获特定领域的上下文，包括工作流程、格式化和其他约定，是编写规则的绝佳起点。
规则也可以通过使用 /Generate Cursor Rules 从现有对话中生成。


## MCP
Model Context Protocol 是一个扩展层，您可以通过它为 Cursor 提供执行操作和获取外部上下文的能力。

    内部文档：例如 Notion、Confluence、Google Docs
    项目管理：例如 Linear、Jira

构建 MCP 服务器 的简短指南：https://modelcontextprotocol.io/tutorials/building-mcp-with-llms


## 自收集上下文
在 Python 中，您可以通过提示 Agent 来实现：

    在代码的相关部分添加 print(“debugging: …”) 语句
    使用终端运行代码或测试
Agent 将读取终端输出并决定下一步要做什么。核心思想是让 Agent 访问实际的运行时行为，而不仅仅是静态代码。

## 如何在 Cursor 中处理大型代码库
### Ask (CTRL+L then select ask not agent)
用于学习和探索的只读模式。Ask 搜索您的代码库并提供答案而不进行任何更改 - 非常适合在修改代码之前理解代码。

### agent 用来干活

## 读懂pdf
微软有mark it down, pdf -> .md
then use cursor to understand it

## confluence page edit
只需装插件，然后talk to AI to generate page
