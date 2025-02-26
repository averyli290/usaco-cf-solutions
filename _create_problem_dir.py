import os

CPP_TEMPLATE_PATH = '_templates/new_template.cpp'
PYTHON_TEMPLATE_PATH = '_templates/python_template.py'

if __name__ == "__main__":
    dir_name = ''.join(filter(lambda x: x.isalnum() or x == '_', [c for c in input().lower().replace(" ", "_")]))
    print("Creating directory {0}...".format(dir_name))
    os.mkdir(dir_name)
    os.popen('cp {0} {1}.cpp'.format(CPP_TEMPLATE_PATH, dir_name + '/' + dir_name)) 
    os.popen('touch {0}'.format(dir_name + '/input')) 
