# gpu_wars
```
  __________________ ____ ___   __      __                      
 /  _____/\______   \    |   \ /  \    /  \_____ _______  ______
/   \  ___ |     ___/    |   / \   \/\/   /\__  \\_  __ \/  ___/
\    \_\  \|    |   |    |  /   \        /  / __ \|  | \/\___ \ 
 \______  /|____|   |______/     \__/\  /  (____  /__|  /____  >
        \/                            \/        \/           \/ 
```

Reproduction of Classic DOS Game (console app)
<hr />
<h2 name="Tests">Unit Tests:</h2>
<p>This program lacks tests. I began working on the game before I was encouraged to start writing tests in my course work, so I intend to include a test suite soon.</p>

<hr />

<h2>Known Issues:
<ul>
<li>When purchasing RX 6800, <tt>display()</tt> function shows the same quantity added to RX 6900
<li>Code is not DRY:
<ul>
<li>There are several functions that have repeated blocks of code with minor differences
<li>These areas, such as `Buy` and `Sell` functions and message blocks for features like Random Events or Sufficient Funds checks, can be made smaller and more readable by reusing code blocks
</ul>
</ul>

<style>
  h2 {
    #color: red;
  }