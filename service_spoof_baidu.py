#encoding: utf-8
import os
import json
import base64
import argparse
import requests
def get_access_token():
    host = 'https://aip.baidubce.com/oauth/2.0/token?grant_type=client_credentials&' \
           'client_id={}&client_secret={}'.format(access_key,secret_key)
    #response = requests.post(host,headers={'Content-Type': 'application/json; charset=UTF-8'})
    response = requests.post(host,timeout=1.5)
    content = response.json()
    return content['access_token']

def faceverify(image_base64):
    access_token = get_access_token()
    host = 'https://aip.baidubce.com/rest/2.0/face/v3/faceverify?' \
           'access_token={}'.format(access_token)
    data = [{'image':image_base64,'image_type':'BASE64'}]

    response = requests.post(host,json=data,timeout=1.5)
    content = response.json()

    return content

def getAllfiles(folder):
    rtn = list()
    for dirfolder, _, imgs in os.walk(folder):
        for img in imgs:
            rtn.append(os.path.join(dirname, img))
    return rtn

def getArgs():
    parse = argparse.ArgumentParser()
    parse.add_argument('-i', '--input', help='input img or folder')
    return vars(parse.parse_args())

if __name__ == '__main__':
    args = getArgs()
    input = args['input']
    if os.path.isfile(input):
        img_paths = [input]
    else:
        img_paths = getAllfiles(input)

    for img_path in img_paths:
        img_name = os.path.basename(img_path)

        spoof_rst = faceverify(base64.b64encode(open(img_path, 'rb').read()))
        print(img_name, spoof_rst)

