Import("env")
import os

token = None
url = None
ssid = None
password = None

def get_value(line):
    return line.split("=")[1].lstrip('"').rstrip().rstrip('"')

if os.path.exists(".env") and os.path.isfile(".env"):
    print("Loading .env file...")
    env_file = open(".env")
    lines = env_file.readlines()

    for line in lines:
        if line.startswith("TOKEN="):
            token = get_value(line)
        if line.startswith("BASE_URL="):
            url = get_value(line)
        if line.startswith("WIFI_NAME="):
            ssid = get_value(line)
        if line.startswith("WIFI_PASSWORD="):
            password = get_value(line)

if token is None:
    raise Exception("Unable to find 'TOKEN' in environment. Please create a '.env' file")
if url is None:
    raise Exception("Unable to find 'BASE_URL' in environment. Please create a '.env' file")
if ssid is None:
    raise Exception("Unable to find 'WIFI_NAME' in environment. Please create a '.env' file")
if password is None:
    raise Exception("Unable to find 'WIFI_PASSWORD' in environment. Please create a '.env' file")

env.Append(CPPDEFINES=[
    ("TOKEN", env.StringifyMacro(token)),
    ("BASE_URL", env.StringifyMacro(url)),
    ("WIFI_NAME", env.StringifyMacro(ssid)),
    ("WIFI_PASSWORD", env.StringifyMacro(password)),
])