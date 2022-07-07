const fs = require('fs');

let rawdata = fs.readFileSync('texture.json');
let tex = JSON.parse(rawdata);

texO = Object.keys(tex.frames).sort().reduce(
    (obj, key) => { 
      obj[key] = tex[key]; 
      return obj;
    }, 
    {}
  );

for (var key in texO) {
    idx = parseInt(key.replace(".png", ""));
    console.log(`// ${key}\n{ ${tex.frames[key].frame.x}, ${tex.frames[key].frame.y}, ${tex.frames[key].frame.w}, ${tex.frames[key].frame.h}, ${tex.frames[key].spriteSourceSize.x}, ${tex.frames[key].spriteSourceSize.y}, ${tex.frames[key].spriteSourceSize.w}, ${tex.frames[key].spriteSourceSize.h} },`);
}
