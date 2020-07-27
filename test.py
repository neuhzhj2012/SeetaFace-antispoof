import cv2
import os
import sys
sys.path.append('libs')
sys.path.append('build')
import bv
sf6=bv.bv_SF6ANTISPOOF()

if __name__ == '__main__':
    img_path='self_AI_all/pos/001.jpg'
    img_name = os.path.basename(img_path)
    img = cv2.imread(img_path)
    
    print('{} real: {}'.format(img_name, sf6.predict(img)))

