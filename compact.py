def format_html_to_c(input_file, output_file):
    with open(input_file, "r") as html_file:
        html_content = html_file.read()

    formatted_content = (
        f'const char MAIN_page[] PROGMEM = R"=====(\n{html_content}\n)=====";'
    )

    with open(output_file, "w") as c_file:
        c_file.write(formatted_content)


output_file = "./src/index.h"
input_file = "./webpage/index.html"

format_html_to_c(input_file, output_file)
