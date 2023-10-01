import htmlmin
from csscompressor import compress as minify_css
from jsmin import jsmin as minify_js

def getContentBetweenTag(content, tag):
    return content.split(f"<{tag}>")[1].split(f"</{tag}>")[0]


def format_html_to_c(input_file, output_file):
    with open(input_file, "r") as html_file:
        html_content = html_file.read()

    # Minificar HTML
    minified_content = htmlmin.minify(
        html_content, remove_comments=True, remove_empty_space=True
    )

    '''

    cssContent = getContentBetweenTag(minified_content, "style")

    # Minificar CSS
    minified_content = minified_content.replace(cssContent, minify_css(cssContent))

    jsContent = getContentBetweenTag(minified_content, "script")

    # Minificar JavaScript
    minified_content = minified_content.replace(jsContent, minify_js(jsContent))

    minified_content = minified_content.replace("\n", "")
    '''

    formatted_content = (
        f'const char MAIN_page[] PROGMEM = R"=====({minified_content})=====";'
    )

    with open(output_file, "w") as c_file:
        c_file.write(formatted_content)


input_file = "index.html"
output_file = "../src/index.h"

format_html_to_c(input_file, output_file)
