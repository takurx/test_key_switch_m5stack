import keyboard
import time
import sys

def on_f13():
    """F13キーが押されたときの処理"""
    print("F13キーが押されました - 'A'を入力します")
    keyboard.write('A')

def on_f14():
    """F14キーが押されたときの処理"""
    print("F14キーが押されました - '😆'を入力します")
    keyboard.write('😆')

def on_f12():
    """f12キーが押されたときの処理"""
    print("f12キーが押されたときの処理 - '🍭✒'を入力します")
    keyboard.write('🍭✒')

def main():
    print("キーボード入力待ち状態です...")
    print("F13 -> A")
    print("F14 -> 😆")
    print("f12 -> 🍭✒")
    print("終了するには Ctrl+C を押してください")
    
    try:
        # F13、F14、f12キーのイベントハンドラを登録
        keyboard.on_press_key('f13', lambda _: on_f13())
        keyboard.on_press_key('f14', lambda _: on_f14())
        keyboard.on_press_key('f12', lambda _: on_f12())
        
        # プログラムを実行し続ける
        keyboard.wait()
        
    except KeyboardInterrupt:
        print("\nプログラムを終了します...")
        sys.exit(0)
    except Exception as e:
        print(f"エラーが発生しました: {e}")
        sys.exit(1)

if __name__ == "__main__":
    main()
