<div align="center"><img src="https://github.com/NuCat7Z/NUCAT/blob/main/Docs/icon-128.jpg?raw=true"> </div>

<div align="center"><h1>NUCAT</h1></div>
<div align="center"><p>开源免费图形化压缩工具</p></div>
NUCAT 是一个压缩软件，它可以帮助你压缩和解压缩文件。它支持多种文件格式，包括 ZIP、RAR、7Z 等。此外，它还具有以下特点：

- **高速操作**：依赖 7ZIP 因此压缩和解压缩速度非常快。
- **创意界面**：依赖 WebView 因此我们可以轻松构建属于自己的皮肤。
- **开箱即用**：NUCAT 的没有上手门槛易于使用。
- **免费开源**：NUCAT 是一款开源免费软件，你可以在 GitHub 上下载它。

## 警告
当前项目未完成，大幅度变动中，近期将完成第一个版本，欢迎各位提交pr与issue完成本项目。

项目进行重构阶段
## 安装

你可以从 GitHub 上下载 NUCAT 的最新版本。

## 使用

你可以通过以下步骤来使用 NUCAT：

1. 下载并安装 NUCAT。
2. 打开 NUCAT。
3. 选择要压缩或解压缩的文件。
4. 点击“压缩”或“解压缩”按钮。
## 其它
编译环境:  WINDOWS + MSVC + CMAKE

代码标准:  17 (严格执行)

依赖资源:  WebView2 RapidJson Curl Bit7z WebView/WebView Wil (无需手动引入) 

## 贡献须知
需要安装以上环境同时 安装Git

## 项目编码 跨平台 界面的设计
内外码: 对Win全面采用UTF8支持,指定A版API的代码页为UTF8 65001支持 (清单设置UTF8代码页)，其余平台均正常保证UTF8

跨平台: 采用大部分标准库实现，对不兼容部分使用条件编译与设计模式编译不同平台代码实现 

界面:交由webview/webview 跨平台的webview视图实现 对多平台良好支撑

## 解释
NuCat 所有代码开源，其主要功能是7zGUI，同时保证上游代码开源，压缩算法与实际功能依赖开源静态库bit7z调用7zip动态库，完成解压与压缩功能。

NuCat并未实现压缩与解压缩等等代码

如果你需要部分代码例如7z.dll 请前往其开源仓库查找

## 感谢
RapidJson/WebView2/7ZIP/Bit7z/Curl/webview/Wil/@Simplxss 为本项目提供了可能

如果你需要更多帮助，可以查看 NUCAT 的文档。
