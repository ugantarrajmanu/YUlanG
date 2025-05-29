const http = require("http");
const express = require("express");
const fs = require("fs");
const { exec } = require("child_process");
const cors = require("cors");

const allowedOrigins = [
  "https://yulang-front.vercel.app/",
  "http://localhost:5173"              
];

const INTERPRETER_PATH = "yulang.out";

const app = express();

const PORT = process.env.PORT || 3000;

app.use(cors({
  origin: function (origin, callback) {
    if (!origin || allowedOrigins.includes(origin)) {
      callback(null, true);
    } else {
      callback(new Error("Not allowed by CORS"));
    }
  },
  methods:["GET", "POST", "OPTIONS"],
  allowedHeaders: ["Content-Type"],
}));

app.use(express.json());


app.post("/api", (req, res) => {
  const received_code = req.body.code.split("\n").join(" ");

  const comm = `echo '${received_code}' | ${INTERPRETER_PATH}`;

  exec(comm, (error, stdout, stderr) => {
    // const output = fs.readFileSync("output");

    res.send(stdout);

    // fs.writeFileSync("output", "");
    // fs.unlinkSync("output", (err) => {
    //   if (err) throw err;
    // });

  });
});

app.get("/api", (req, res) => {
  res.send("Server Running.....");
});

app.listen(PORT, () => console.log(`Server running on port ${PORT}`));
