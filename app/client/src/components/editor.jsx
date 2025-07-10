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
      <div className="editor-container" style={{backgroundColor: "#000000"}}>
        <Editor
          className="code-editor"
          theme="hc-black"
          defaultValue={code}
          onChange={(code) => {
            setCode(code);
          }}
        />
      </div>
    </div>
  );
};
