from tkinter import *
from tkinter import messagebox as mb
import ctypes

# void fill_fibonacci(int *array, int size)
# int transfer_nums(int *array_1, int *array_2, int size)

lib_arr = ctypes.CDLL("./libarr.so")

__fill_fibonacci = lib_arr.fill_fibonacci
__fill_fibonacci.argtypes = (ctypes.POINTER(ctypes.c_int), ctypes.c_int)
__fill_fibonacci.restype = None

__transfer_nums = lib_arr.transfer_nums
__transfer_nums.argtypes = (ctypes.POINTER(ctypes.c_int), ctypes.POINTER(ctypes.c_int), ctypes.c_int)
__transfer_nums.restype = ctypes.c_int

def fill_fibonacci(event):
    def read_size():
        arr_size = entry_size.get()
        try:
            arr_size = int(arr_size)
        except (ValueError):
            arr_size = 0
        return arr_size

    def fill_array(event):
        arr_size = read_size()
        arr = (ctypes.c_int * arr_size)()
        __fill_fibonacci(arr, arr_size)
        arr_to_label(arr, len(arr), 1)
        input_size.destroy()
        
    # make new window to input size of aray
    input_size = Toplevel()
    input_size.geometry("300x80")
    input_size.configure(bg = "black")
    input_size.title("Input size")

    Label(input_size, \
        text = "Enter the size of array", \
        bg = but_bg_color,
        fg = but_fg_color).pack()
    
    entry_size = Entry(input_size)
    entry_size.pack()

    but_fill = Button(input_size, \
        text = "Fill", \
        bg = but_bg_color,
        fg = but_fg_color)
    but_fill.bind("<Button-1>", fill_array)
    but_fill.pack()

def arr_input(event):
    def arr_enter(event):
        source_arr = label_to_arr()
        try:
            str_arr = entry_arr.get()

            array = str_arr.split()
            for i in range(len(array)):
                array[i] = int(array[i])
            
            arr_to_label(array, len(array), 1)
            
        except (ValueError):
            mb.showerror("ERROR", "Incorrect symbols. Please, \
            enter numbers spliting by spaces.")
            arr_to_label(source_arr, len(source_arr), 1)
        finally:
            input_arr.destroy()

    # make new window to input array
    input_arr = Toplevel()
    input_arr.title("Input array")
    input_arr.geometry("300x80")
    input_arr.configure(bg = "black")

    Label(input_arr, \
        text = "Enter numbers of array spliting by spaces", \
        bg = but_bg_color,
        fg = but_fg_color).pack()
    
    entry_arr = Entry(input_arr)
    entry_arr.pack()

    but_fill = Button(input_arr, \
        text = "Enter", \
        bg = but_bg_color,
        fg = but_fg_color)
    but_fill.bind("<Button-1>", arr_enter)
    but_fill.pack()

def transfer_nums(even):
    arr = label_to_arr()
    arr = (ctypes.c_int * len(arr))(*arr)
    arr2 = (ctypes.c_int * len(arr))()
    size2 = __transfer_nums(arr, arr2, len(arr))
    arr_to_label(arr2, size2, 2)



def arr_to_label(array, size, lbl_num):
    str_arr = ""
    for i in range(size):
        str_arr += str(array[i]) + " "
    if (size == 0):
        str_arr = "empty"

    if (lbl_num == 1):
        label_arr.configure(text = str_arr)
    else:
        label_arr2.configure(text = str_arr)

def label_to_arr():
    arr = label_arr["text"]
    if (arr != "empty"):
        arr = arr.split()
        for i in range(len(arr)):
            arr[i] = int(arr[i])
    else:
        arr = []
    return arr

but_bg_color = "black"
but_fg_color = "white"
but_width = 30

window = Tk()
window.geometry("400x200")
window.title("ARR PROCESSING")
window.configure(bg = "black")

Label(window, text = "")
label_array = Label(window, \
                text = "First array: ", \
                bg = but_bg_color,
                fg = but_fg_color)
label_array.pack()
label_arr = Label(window, \
                text = "empty", \
                bg = but_bg_color,
                fg = but_fg_color)
label_arr.pack()

label_array2 = Label(window, \
                text = "Second array: ", \
                bg = but_bg_color,
                fg = but_fg_color)
label_array2.pack()
label_arr2 = Label(window, \
                text = "empty", \
                bg = but_bg_color,
                fg = but_fg_color)
label_arr2.pack()

but_input = Button(window, \
                text = "Input first array", \
                bg = but_bg_color,
                fg = but_fg_color,
                width = but_width)
but_input.bind("<Button-1>", arr_input)
but_input.pack()

but_fibonacci = Button(window, \
                text = "Input first array by Fibonacci numbers", \
                bg = but_bg_color,
                fg = but_fg_color,
                width = but_width)
but_fibonacci.bind("<Button-1>", fill_fibonacci)
but_fibonacci.pack()

but_transfer = Button(window, \
                text = "Transfer numbers from first \narray to second (first occurence)", \
                bg = but_bg_color,
                fg = but_fg_color,
                width = but_width)
but_transfer.bind("<Button-1>", transfer_nums)
but_transfer.pack()

window.mainloop()