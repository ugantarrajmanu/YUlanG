import Editor from "@monaco-editor/react";
import "./editor.css";

export const YEditor = ({ onClick, code, setCode }) => {
  return (
    <div className="second-editor-container">
      <div className="header">
        <h1 className="yulang">YUlanG</h1>
        <button className="run-button" onClick={onClick}>
          Run
        </button>
      </div>
      <div className="editor-container">
        <Editor
          className="code-editor"
          theme="vs-dark"
          defaultValue={code}
          option={{
            fontSize: 20,
            padding: {
              top: 50,
            },
          }}
          onChange={(code) => {
            setCode(code);
          }}
        />
      </div>
    </div>
  );
};
