<h1>0x16. C - Simple Shell</h1>

<h2>Background Context</h2>
<p>Write a simple UNIX command interpreter</p>

![alt-text](https://s3.amazonaws.com/intranet-projects-files/holbertonschool-low_level_programming/235/shell.jpeg)

<h2>Tasks :page_with_curl:</h2>
<h3>0.Betty would be proud</h3>
<p>Write a beautiful code that passes the Betty checks</p>

<hr>

<h3>1. Simple shell 0.1</h3>
<p>Write a UNIX command line interpreter.</p>
<ul>
<li>Usage: <code>simple_shell</code></li>
</ul>
<p>You Shell should:</p>
<ul>
    <li>Display a prompt and wait for the user to type a command. A command line always ends with a new line.</li>
    <li>The prompt is displayed again each time a command has been executed.</li>
    <li>The command lines are simple, no semicolons, no pipes, no redirections or any other advanced features.</li>
    <li>The command lines are made only of one word. No arguments will be passed to programs.</li>
    <li>If an executable cannot be found, print an error message and display the prompt again. Handle errors.</li>
    <li>You have to handle the “end of file” condition (<code>Ctrl+D</code>)</li>
</ul>
<p>You don't have to:</p>
<ul>
    <li>use the <code>PATH</code></li>
    <li>implement built-ins</li>
    <li>handle special characteres: <code>"</code>, <code>'</code>, <code>`</code>, <code>\</code>, <code>*</code>, <code>&</code>, <code>#</code></li>
    <li>be able to move the cursor</li>
    <li>handle commands with arguments</li>
</ul>
<p><em><code>execve</code> will be the core part of your Shell, don't forget to pass the environ to it...</em></p>

<hr>

<h3>2. Simple shell 0.2</h3>
<p>Simple shell 0.1 +</p>
<ul>
    <li>Handle command lines with arguments</li>
</ul>

<hr>

<h3>3. Simple shell 0.3</h3>
<p>Simple shell 0.2 +</p>
<ul>
    <li>Handle the <code>PATH</code></li>
    <li><code>fork</code> must not be called if the command doesn't exist</li>
</ul>

<hr>

<h3>4. Simple shell 0.4</h3>
<p>Simple shell 0.3 +</p>
<ul>
    <li>Implement the <code>exit</code> built-in, that exits the shell</li>
    <li>Usage: <code>exit</code></li>
    <li>You don't have to handle any argument to the built-in <code>exit</code></li>
</ul>

<hr>

<h3>5. Simple shell 1.0</h3>
<p>Simple shell 0.4 +</p>
<ul>
    <li>Implement the <code>env</code> <strong>built-in</strong>, that prints the current environment</li>
</ul>

<hr>

<h3>6. Simple shell 0.1.1</h3>
<p>Simple shell 0.1 +</p>
<ul>
    <li>write your own <code>getline</code> function</li>
    <li>Use a buffer to read many chars at once and call the least possible the <code>read</code> system call</li>
    <li>You will need to use <code>static</code> variables</li>
    <li>You are not allowed to use <code>getline</code></li>
</ul>
<p>You don't have to:</p>
<ul>
    <li>be able to move the cursor</li>
</ul>

<hr>

<h3>7. Simple shell 0.2.1</h3>
<p>Simple shell 0.2 +</p>
<ul>
    <li>You are not allowed to use <code>strtok</code></li>
</ul>

<hr>

<h3>8. Simple shell 0.4.1</h3>
<p>Simple shell 0.4 +</p>
<ul>
    <li>Handle arguments for the built-in <code>exit</code></li>
    <li>Usage: <code>exit status</code>, where <code>status</code> is an integer used to exit the shell</li>
</ul>

<hr>

<h3>9. setenv, unsetenv</h3>
<p>Simple shell 1.0 +</p>
<p>Implement the <code>setenv</code> and <code>unsetenv</code> builtin commands</p>
<ul>
    <li><code>setenv</code></li>
    <ul>
        <li>Initialize a new environment variable, or modify an existing one</li>
        <li>Command syntax: <code>setenv VARIABLE VALUE</code></li>
        <li>Should print something on stderr on failure</li>
    </ul>
    <li><code>unsetenv</code></li>
    <ul>
        <li>Remove an environment variable</li>
        <li>Command syntax: <code>unsetenv VARIABLE</code></li>
        <li>Should print something on stderr on failure</li>
    </ul>
</ul>

<hr>

<h3>10. cd</h3>
<p>Simple shell 1.0 +</p>
<p>Implement the builtin command <code>cd</code>:</p>
<ul>
    <li>Change the current directory of the process.</li>
    <li>Command syntax: <code>cd [DIRECTORY]</code></li>
    <li>If no argument is given to <code>cd</code> the command must be interpreted like <code>cd $HOME</code></li>
    <li>You have to handle the command <code>cd -</code></li>
    <li>You have to update the environment variable <code>PWD</code> when you change directory</li>
</ul>
<p><code>man chdir</code>, <code>man getcwd</code></p>

<hr>

<h3>11. ;</h3>
<p>Simple shell 1.0 +</p>
<ul>
    <li>Handle cthe commands separator <code>;</code></li>
</ul>

<hr>

<h3>12. && and ||</h3>
<p>Simple shell 1.0 +</p>
<ul>
    <li>Handle the <code>&&</code> and <code>||</code> shell logical operators</li>
</ul>

<hr>

<h3>13. alias</h3>
<p>Simple shell 1.0 +</p>
<ul>
    <li>Implement the <code>alias</code> builtin command</li>
    <li>Usage: <code>alias [name[='value'] ...]</code></li>
    <ul>
        <li><code>alias</code>: Prints a list of all aliases, one per line, in the form <code>name='value'</code></li>
        <li><code>alias name [name2 ...]</code>: Prints the aliases <code>name</code>, <code>name2</code>, etc 1 per line, in the form <code>name='value'</code></li>
        <li><code>alias name='value' [...]</code>: Defines an alias for each <code>name</code> whose <code>value</code> is given. If <code>name</code> is already an alias, replaces its value with <code>value</code></li>
    </ul>
</ul>

<hr>

<h3>14. Variables</h3>
<p>Simple shell 1.0 +</p>
<ul>
    <li>Handle variables replacement</li>
    <li>Handle the <code>$?</code> variable</li>
    <li>Handle the <code>$$</code> variable</li>
</ul>

<hr>

<h3>15. Comments</h3>
<p>Simple shell 1.0 +</p>
<ul>
    <li>Handle comments (<code>#</code>)</li>
</ul>

<hr>

<h3>16. File as input</h3>
<p>Simple shell 1.0 +</p>
<ul>
    <li>Usage: <code>simple_shell [filename]</code></li>
    <li>Your shell can take a file as a command line argument</li>
    <li>The file contains all the commands that your shell should run before exiting</li>
    <li>The file should contain one command per line</li>
    <li>In this mode, the shell should not print a prompt and should not read from <code>stdin</code></li>
</ul>
