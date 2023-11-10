# F303_Mbed_Template

## これはなに？

Nucleo f303k8 を PlatformIO で mbed で開発するときのテンプレートです

## 特徴

- mbedignore が設定してあるのでコンパイルが早い
- PlatformIO でも mbed OS v6.15 が使える

## 注意

mbedignore でコンパイルが省略されている機能を使用するときは`.mbedignore`ファイルを編集してください

## 使い方

1. Use This Template を押して新しいリポジトリを作る
1. clone してくる
1. VSCode で開く
1. VSCodeの画面下のターミナルのアイコンを開き、`pio system info`を実行して、python executableのパスをコピーする
![image](https://user-images.githubusercontent.com/42294158/193441843-c60f4508-5ce7-407b-a729-f37bd8822ad9.png)
![image](https://user-images.githubusercontent.com/42294158/193441875-a5dda286-e0c9-47c3-a6b3-673de7359cf7.png)

1. ターミナルで`<python executableのパス> -m pip install jinja2 intelhex future prettytable six jsonschema`する
1. 普通の PlatformIO プロジェクトとして使う
