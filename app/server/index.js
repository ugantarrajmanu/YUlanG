const http = require("http");
const express = require("express");
const fs = require("fs");
const { exec } = require("child_process");
const cors = require("cors");

const allowedOrigins = [
  "https://yulang-front.vercel.app",
  "http://localhost:5173"              
];

const app = express();

const PORT = process.env.PORT || 3000;

const corsOptions = {
  origin: function (origin, callback) {
    if (!origin || allowedOrigins.includes(origin)) {
      callback(null, true);
    } else {
      callback(new Error("CORS not allowed"));
    }
  },
  methods: ["GET", "POST", "OPTIONS"],
  allowedHeaders: ["Content-Type"],
  credentials: true
};

app.use(cors(corsOptions));
// app.options("*", cors(corsOptions));

app.use(express.json());

app.post("/api/yulang", (req, res) => {
  const received_code = req.body.code.split("\n").join(" ").replace(/"/g, '\\"');

  console.log(received_code);

  const comm = `echo "${received_code}" > output && ./Interpreter/yulang ./output && rm output`;

  exec(comm, (error, stdout, stderr) => {
    if (error) {
      console.log("stderr: ", stderr);
      return res.status(500).send(stderr || "Unknown Execution Error");
    }

    if (stderr) {
      console.log("stderr: ", stderr);
      return res.status(400).send(stderr || "Unknown Execution Error");
    } 

    console.log("stdout: ", stdout);
    return res.status(200).send(stdout);

  });
});

app.get("/api/yulang", (req, res) => {
  res.send("Server Running.....");
});

app.listen(PORT, () => console.log(`Server running on port ${PORT}`));
