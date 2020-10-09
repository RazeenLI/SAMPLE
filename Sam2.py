from flask import Flask, send_file, request
import json
APP = Flask(__name__)


@APP.route("/")
def hello():
    return "Hello world"


@APP.route("/润泽", methods=['GET'])
def data1():
    Razeen = {}
    Razeen['Name'] = request.args.get('data1')
    Razeen['age'] = request.args.get('data2')
    return json.dumps(Razeen)


@APP.route("/img")
def img():
    return send_file("/Users/eraser_mbp/Pictures/IMG_0372.PNG", mimetype='image/png')


@APP.route("/file")
def file():
    return send_file(" /Users/eraser_mbp/Documents/UNSW/20T3\ 课程要求.html")


if __name__ == "__main__":
    APP.run(port=5000)