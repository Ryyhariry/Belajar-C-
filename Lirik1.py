import sys
import time

def jalanin_lirik():
    lirik = [
        ("Sudah terbiasa terjadi tante...", 0.09),
        ("Teman datang ketika lagi butuh saja", 0.11),
        ("Coba kalau lagi susah...", 0.11),
        ("Mereka semua menghilaaaaaaaaang...", 0.08),
        ("Apakah spek standar seperti ini yang para pemirsa inginkan?", 0.05),
        ("Tanteeee...", 0.08)
    ]
    delay = [0.3, 0.3, 0.4, 0.3, 0.5, 0.3, 0.4]
    print("\n== Tanteeeee ==")
    time.sleep(2)
    for i, (line, delay_karakter) in enumerate(lirik):
        for karakter in line:
            print(karakter, end='')
            sys.stdout.flush()
            time.sleep(delay_karakter)
        time.sleep(delay[i])
        print('')
    print("// code by ryy")
  
jalanin_lirik()
