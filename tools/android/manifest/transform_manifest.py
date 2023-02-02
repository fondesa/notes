from xml.etree import ElementTree as ET
import argparse

parser = argparse.ArgumentParser()
parser.add_argument("--input", required=True)
parser.add_argument("--output", required=True)
parser.add_argument("--min-sdk", type=int, required=True)
parser.add_argument("--target-sdk", type=int, required=True)
args = parser.parse_args()

ET.register_namespace("android", "http://schemas.android.com/apk/res/android")
tree = ET.parse(args.input)
root = tree.getroot()

uses_sdk_declaration = root.find("uses-sdk")

if uses_sdk_declaration is not None:
    print("Manifest element <uses-sdk> already declared, skipping transform")
    quit()

uses_sdk_attributes = {
    "xmlns:android": "http://schemas.android.com/apk/res/android",
    "android:minSdkVersion" : str(args.min_sdk),
    "android:targetSdkVersion" : str(args.target_sdk)
}

ET.SubElement(root, "uses-sdk", uses_sdk_attributes)
tree.write(args.output)

print("Added min-sdk and target-sdk to manifest")
