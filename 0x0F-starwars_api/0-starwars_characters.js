#!/usr/bin/node
const request = require('request');

function getCharacter (url) {
  return new Promise((resolve, reject) => {
    request(url, (error, response, body) => {
      if (!error && response.statusCode === 200) {
        resolve(body);
      } else {
        reject(error);
      }
    });
  });
}

async function printName (url) {
  const body = await getCharacter(url);
  console.log(JSON.parse(body).name);
}

request('https://swapi-api.hbtn.io/api/films/' + process.argv[2], async function (error, response, body) {
  if (!error && response.statusCode === 200) {
    const charUrls = JSON.parse(body).characters;
    for (const url of charUrls) {
      await printName(url);
    }
  }
});