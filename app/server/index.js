const http = require("http");
const express = require("express");
const fs = require("fs");
const { exec } = require("child_process");
const CORS = require("cors");

const INTERPRETER_PATH = "yulang.exe";

const app = express();
const PORT = 9000;
app.use(CORS());

app.use(express.json());
app.post("/", (req, res) => {
  const received_code = req.body.code.split("\n").join(" ");
  
  const comm = `echo ${received_code} | ${INTERPRETER_PATH} > output`;

  exec(comm, (error, stdout, stderr) => {
    // if (error) {
    //   console.error(`error: ${error.name}`);
    // }
    // if (stderr) {
    //   console.error(`stderr: ${stderr}`);
    // }

    if (!stderr && !error) {
      console.log(`${stdout}`);
      // fs.writeFileSync("./output_file/output", stdout);
    }
    res.send("Received");
  });
});

app.get("/", (req, res) => {
  const output = fs.readFileSync("./output");

  // console.log(output);

  res.send(output);

  fs.writeFileSync("./output_file/output", "");
  fs.unlinkSync("./output_file/output", (err) => {
    if (err) throw err;
  });
});

app.listen(PORT, () => console.log(`Server running on port ${PORT}`));
