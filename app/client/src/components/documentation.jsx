import "./documentation.css";

export function Documentation({ setVis }) {
  return (
    <div className="manual">
      {
        <div style={{ position: "relative" }}>
          <div
            className="manual-header"
            style={{
              display: "flex",
              justifyContent: "space-between",
              alignItems: "center",
            }}
          >
            <h1 id="yulang">YUlanG</h1>
            <button className="close-button" onClick={setVis}>
              <span style={{ fontSize: "2rem" }}>×</span>
            </button>
          </div>

          <div className="manual-content">
            <p>
              <strong>YUlanG</strong> is an interpreted Esoteric Programming
              Language.
            </p>
            <ul>
              <li>
                <p>
                  It uses{" "}
                  <strong>
                    <code>FLEX</code>
                  </strong>{" "}
                  lexer for finding lexeme and token.
                </p>
              </li>
              <li>
                <p>
                  It uses{" "}
                  <strong>
                    <code>BISON</code>
                  </strong>{" "}
                  parser for generating annotated parser tree and then
                  evaluating line by line (interpreter).
                </p>
              </li>
            </ul>
            <h2 id="what-is-an-interpreter">What is an Interpreter?</h2>
            <p>
              An interpreter is a program that converts the High Level Language
              like Python, JavaScript, etc. to machine readable language i.e.
              Low Level Language.
            </p>
            <p>
              The interpreter reads and evaluates the program in High Level
              Language line by line. Therefore it runs the program to the line
              where error is there.
            </p>
            <p>Let's take Python for example:</p>
            <pre>
              <code>{`n = 5
print("n -> ", n)
u = 7
print("u -> ", u)
prit("n+u -> ", n+u)  # typo!`}</code>
            </pre>
            <p>This program gives output:</p>
            <pre>
              <code>{`n -> 5
u -> 7
ERROR!
Traceback (most recent call last):
  File "<main.py>", line 5, in <module>
NameError: name 'prit' is not defined. Did you mean: 'print'?`}</code>
            </pre>
            &nbsp;
            <hr />
            <h1 id="getting-started">
              <strong>Getting Started</strong>
            </h1>
            <h2 id="run-your-first-yulang-program">
              Run Your First YUlanG Program
            </h2>
            <pre>
              <code>{`yug "Hello Butterflies" likhna hai`}</code>
            </pre>
            <p>Output:</p>
            <pre>
              <code>{`"Hello Butterflies"`}</code>
            </pre>
            &nbsp;
            <hr />
            &nbsp;
            <h2 id="1-variable-numbers-and-strings">
              1. Variable, Numbers and Strings
            </h2>
            <h3 id="1-1-variable">1.1 Variable</h3>
            <ul>
              <li>
                A <code>variable</code> is a location in memory where we store
                data.
              </li>
              <li>
                At present, <code>YUlanG</code> supports only int and string
                data types.
              </li>
              <li>
                Variable Definition: <code>arey yug a = 5 int hai</code>
              </li>
            </ul>
            <pre>
              <code>{`yug a = 5 int hai
yug b = "Hello Titli" string hai;`}</code>
            </pre>
            &nbsp;
            <h3 id="1-2-number">1.2 Number</h3>
            <p>
              YUlanG, at present, only supports <code>int</code> data type.
            </p>
            <pre>
              <code>{`arey yug a = 5 int hai`}</code>
            </pre>
            &nbsp;
            <h3 id="1-3-string">1.3 String</h3>
            <p>
              YUlanG supports strings. A string is a sequence of characters.
            </p>
            <pre>
              <code>{`arey yug a = "Hello Titli" string hai`}</code>
            </pre>
            &nbsp;
            <hr />
            <h2 id="2-control-flow">2. Control Flow</h2>
            <h3 id="2-1-if-else">2.1 If, Else</h3>
            <p>Structure of if condition:</p>
            <pre>
              <code>{`yug agar (condition) hai to {
  do something
}`}</code>
            </pre>
            <pre>
              <code>{`yug agar (5 < 7) hai to {
  yug "Hello Titli" likhna
}`}</code>
            </pre>
            <pre>
              <code>{`"Hello Titli"`}</code>
            </pre>
            <p>Structure of If-Else condition:</p>
            <pre>
              <code>{`yug agar (condition) hai to {
  do something
} nahi to {
  do something
}`}</code>
            </pre>
            <pre>
              <code>{`yug a = 5 int hai

yug agar (a % 2 == 0) hai to {
  yug "Even" likhna hai
} nahi to {
  yug "Odd" likhna hai
}`}</code>
            </pre>
            <pre>
              <code>{`"Odd"`}</code>
            </pre>
            &nbsp;
            <h3 id="2-2-for-loop">2.2 For Loop</h3>
            <p>For loop is used to iterate.</p>
            <p>Structure of for loop:</p>
            <pre>
              <code>{`yug i ko [start] se [end] tak lejana hai {
  do something
}`}</code>
            </pre>
            <pre>
              <code>{`yug i ko 0 se 5 tak lejana hai {
  yug i likhna hai
}`}</code>
            </pre>
            <pre>
              <code>{`0
1
2
3
4`}</code>
            </pre>
            <pre>
              <code>{`yug i = 5 int hai
yug i ko 8 tak le jana hai {
  yug i likhna hai
}`}</code>
            </pre>
            <pre>
              <code>{`5
6
7`}</code>
            </pre>
          </div>
        </div>
      }
    </div>
  );
}
