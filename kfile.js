let project = new Project('DavesWorld');

project.kore = false;
project.cmd = true;

project.addFile('Sources/**');
project.setDebugDir('./Deployment');

resolve(project);
