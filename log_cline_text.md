# Log, cline

## No.1
m5stackをUSB keyboardとして、Aボタンを押したら"A"をkey入力、Aボタンを押したら"😆"をkey入力、Cボタンを押したら"🍭✒"をkey入力するファームウェアを作成してください
- constraint condition
現在のtest_key_switch_m5stackフォルダをもとに
platformioを使用する
m5stack esp32のファームウェアを作る

## No.2
bleKeyboard.printがうまくいってないようだ。原因を調査して、readmeに記載する内容を考えてください
- success
  - Serial.printlnはOK
  - bleKeyboard.print("A");
  →A

- failure
  - M5stackの画面上の文字化け
  - bleKeyboard.print("😆");
  →tm
  - bleKeyboard.print("🍭✒");
  →tb82qg

