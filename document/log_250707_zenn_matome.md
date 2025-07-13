# M5Stackで絵文字入力できるキーボードボタンができるか試した→HID keyboard tableで1byte文字しか送れないので、絵文字入力はM5Stack+受信待ちソフトの構成が良さそう

# やったこと
- M5Stackで絵文字入力できるキーボードボタンができるか試した
    - M5Stack BasicはUSB HIDのArduinoのライブラリが難しいので、BLE経由で作った
        - → 絵文字は文字化けした。ESP32のBLE keyboardライブラリの制限かと思ったので、M5Stack S3のUSB HIDで試す
    - M5Stack S3はUSB HIDのArduinoのライブラリがあるので、USB HID経由で作った
        - → 絵文字は文字化けした。他の方法を考える必要がある。
        - HID keyboard tableにはASCII codeなど1 byteの文字しか入力通信できなくて、絵文字のようなマルチバイト文字を直接入力することはできない
- その他１、ClineのログのExportの仕方
    - 時計ボタン🕑を押す→EXPORTボタンを押す
- その他２、GitHub Actionsのworkflowもclineから追加してみた
    - うまく動いた、やったぜ
　
## 次にやれたら良いこと
- M5Stackからボタン入力+PC側で特定のキーを受信したら絵文字入力するプログラム、みたいな構成の方が良さそう
    - M5Stack → BLE, keyboard入力 Function key 13~24 → Python 的な
        - HID keyboard入力かSerial入力か
    - またはIMEに出力するように各OSに合わせる、Android用やiPhone用
- M5Stack上の表示も文字化けしているので、絵文字が入っている組み込みフォントを試す
- このテキストもclineで自動で作成できるのでは？次試す

# M5Stackで絵文字入力できるキーボードボタンができるか試した
- M5StackでPCまたはスマホで絵文字入力がさくっとできるボタンが作れそうだなと思ってやってみた
- 作成案
    - m5stackをUSB keyboardとして、Aボタンを押したら"A"をkey入力、Aボタンを押したら"😆"をkey入力、Cボタンを押したら"🍭✒"をkey入力するファームウェアの作成

## M5Stack BasicはUSB HIDのArduinoのライブラリが難しいので、BLE経由で作った
- [test_key_switch_m5stack/test_key_switch_m5stack_basic at main · takurx/test_key_switch_m5stack](https://github.com/takurx/test_key_switch_m5stack/tree/main/test_key_switch_m5stack_basic)
- M5StackのLCD文字が文字化けしている
- 出力が絵文字のときは文字化けした
    - 例: "😆" → "tm", "🍭✒" → "tb82qg"

## M5Stack S3はUSB HIDのArduinoのライブラリがあるので、USB HID経由で作った
- [test_key_switch_m5stack/test_key_switch_m5stack_s3 at main · takurx/test_key_switch_m5stack](https://github.com/takurx/test_key_switch_m5stack/tree/main/test_key_switch_m5stack_s3)
- M5StackのLCD文字が文字化けしている
- 出力が絵文字のときは文字化けした
    - 例: "😆" → "tm", "🍭✒" → "tb82qg"
- USB HIDのプログラムを書き込むと通常通り書き込めなくなるが、リセットボタンを長押しで書き込みモードに入ることができる

## その他１、ClineのログのExportの仕方
- ①時計ボタン🕑を押す→②EXPORTボタンを押す
- Reference:
    - [Save task and chat to a Markdown File · cline/cline · Discussion #2352](https://github.com/cline/cline/discussions/2352)

## その他２、GitHub Actionsのworkflowもclineから追加してみた
- うまく動いた、やったぜ
- [test_key_switch_m5stack/.github/workflows/build.yml at main · takurx/test_key_switch_m5stack](https://github.com/takurx/test_key_switch_m5stack/blob/main/.github/workflows/build.yml)
