#!/usr/bin/env python3

import os
import sys
from pynput import keyboard
from queue import Queue
import wonderwords as wm
from colorama import Fore


def on_press(key):
    key_queue.put(key)


listener = keyboard.Listener(on_press=on_press)
listener.start()

key_queue = Queue()

bundle = wm.RandomWord().random_words(10)

for word in bundle:
    use_guess = ""
    next = False
    for c in word:
        correct_word = False
        if next:
            break
        while not correct_word:
            os.system('clear')
            print(bundle)
            print(Fore.GREEN + use_guess)
            latest_key = key_queue.get()
            user_input = getattr(latest_key, 'char', None)
            if latest_key == keyboard.Key.esc:  # ASCII for Ctrl+C
                print("\nExiting game...")
                listener.stop()
                sys.exit()
            if latest_key == keyboard.Key.space:
                next = True
                break
            if user_input is None:
                continue
            if user_input.lower() == c.lower():
                print("\ncorrect")
                use_guess += user_input.lower()
                correct_word = True
                while not key_queue.empty():
                    key_queue.get()

            else:
                print(f"\nwrong you typed {user_input}")
