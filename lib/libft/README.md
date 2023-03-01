# Libft - Project #00

[![xvoorvaa's 42 Libft Score](https://badge42.vercel.app/api/v2/cl1l0g8q3005209mm02a81gfy/project/2020487)](https://github.com/JaeSeoKim/badge42)

### Workflows to check Linux and macOS compilation:

[![Libft macOS compile check CI](https://github.com/xvoorvaa/libft/actions/workflows/MacOs_compilation.yml/badge.svg)](https://github.com/xvoorvaa/libft/actions/workflows/MacOs_compilation.yml)

[![Libft Ubuntu compile check CI](https://github.com/xvoorvaa/libft/actions/workflows/ubuntu_compilation.yml/badge.svg)](https://github.com/xvoorvaa/libft/actions/workflows/ubuntu_compilation.yml)

<h2> Description Libft</h2>   
<p>The goal of this project is create small functions that you can combine to create your own library. These functions need to be able to act like the real functions from the C library and also manage the same error handling.</p>
<h2>Installation</h2>

*To build the programm there is only a few steps: First of all, you can download the repository through the following steps in any shell of your preference:*
<br>
<pre>
git clone git@github.com:xvoorvaa/libft.git
cd libft
make
</pre>
This commands will compile everything and a executable "libft" should be created.
<br><br>
![how_to_libft_v1](https://user-images.githubusercontent.com/56308735/161396797-3ccd33ab-cf12-4585-b3c8-05e2d874619b.gif)

<h2>Functions from <code style="color:#78dda5;">&lt;ctype.h&gt;</code> library </h2>

<li>ft_isalnum - alphanumeric character test.</li>
<li>ft_isalpha - alphabetic character test.</li>
<li>ft_islower * - lower-case character test.</li>
<li>ft_isupper * - upper-case character test.</li>
<li>ft_isdigit - decimal-digit character test.</li>
<li>ft_isprint - printing character test (space character inclusive).</li>
<li>ft_tolower - upper case to lower case letter conversion.</li>
<li>ft_toupper - lower case to upper case letter conversion.</li>
<br>
<h2>Functions from <code style="color:#78dda5;">&lt;stdlib.h&gt;</code> library </h2>
<li>ft_atoi - convert ASCII string to integer.</li>
<li>ft_calloc - memory allocation.
<br><br>
<h2>Functions from <code style="color:#78dda5;">&lt;strings.h&gt;</code> library </h2>
<li>ft_bzero - write zeroes to a byte string.</li>
<li>ft_memset - write a byte to a byte string.</li>
<li>ft_memchr - locate byte in byte string.</li>
<li>ft_memcmp - compare byte string.</li>
<li>ft_memmove - copy byte string.</li>
<li>ft_memcpy - copy memory area.</li>
<li>ft_memccpy - copy string until character found.</i>
<br><br>
<h2>Functions from <code style="color:#78dda5;">&lt;string.h&gt;</code> library </h2>
<li>ft_strlen - find length of string.</li>
<li>ft_strchr - locate character in string (first occurrence).</li>
<li>ft_strrchr - locate character in string (last occurence).</li>
<li>ft_strstr * - locate a substring in a string.</li>
<li>ft_strnstr - locate a substring in a string (size-bounded).</li>
<li>ft_strcmp * - compare strings.</li>
<li>ft_strncmp * - compare strings (size-bounded).</li>
<li>ft_strcpy * - copy strings.</li>
<li>ft_strncpy * - copy strings (size-bounded).</li>
<li>ft_strdup - save a copy of a string (with malloc).</li>
<li>ft_strndup * - save a copy of a string (with malloc, size-bounded).</li>
<li>ft_strncat * - concatenate strings (s2 into s1, size-bounded).</li>
<li>ft_strlcpy - size-bounded string copying.</li>
<li>ft_strlcat - size-bounded string concatenation.</li>
<br>
<h2>Non standard functions </h2>
<li>ft_putchar_fd - output a character to given file.</li>
<li>ft_putstr_fd - output string to given file.</li>
<li>ft_putnbr_fd - output integer to given file.</li>
<li>ft_itoa - convert integer to ASCII string.</li>
<li>ft_substr - extract substring from string.</li>
<li>ft_strtrim - trim beginning and end of string with the specified characters.</li>
<li>ft_strjoin - concatenate two strings into a new string (with malloc).</li>
<li>ft_split - split string, with specified character as delimiter, into an array of strings.</li>
<h2>Usage 🛠️</h2>
<br>
<p>To compile the library, run the following command:</p>
<pre>
cd path_to_libft && make
</pre>
<p>After creating the library, you're able to use the functions within another file. <em>to do that add the folowing as header in a file:</em></p>

<pre>
#include "libft.h"
</pre>
<br>
<h2>Third-party testers</h2>
<li><a href="https://github.com/Tripouille/libftTester">libftTester-Tripouille</a></li>
<li><a href="https://github.com/y3ll0w42/libft-war-machine">War-machine-Y3ll0w42</a></li>
<li><a href="https://github.com/alelievr/libft-unit-test">Unit-tester-Alelievr</a></li>
