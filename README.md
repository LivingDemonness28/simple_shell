<h1>0x16. C - Simple Shell</h1>

<h2>Background Context</h2>
<p>Write a simple UNIX command interpreter</p>

!(alt-text)[https://s3.amazonaws.com/intranet-projects-files/holbertonschool-low_level_programming/235/shell.jpeg]

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