# Code of Conduct

## Our Pledge

We as contributors and maintainers of the Teacher-AIPU project pledge to make
participation in this project a harassment-free experience for everyone,
regardless of age, body size, disability, ethnicity, gender identity,
experience level, nationality, personal appearance, race, religion, or
sexual identity and orientation.

## Our Standards

**Positive behaviour includes:**
- Using welcoming and inclusive language
- Being respectful of differing viewpoints and experience levels
- Gracefully accepting constructive criticism
- Focusing on what is best for the project
- Showing empathy towards other contributors

**Unacceptable behaviour includes:**
- Trolling, insulting, or derogatory comments
- Public or private harassment
- Publishing others' private information without permission
- Plagiarising hardware designs or RTL without attribution
- Other conduct which could reasonably be considered inappropriate

## Hardware & Safety Standards

Because this project involves physical hardware (FPGA, ESP32, power rails):

- Never instruct others to connect voltages outside the rated specs of any
  component (Tang Primer 20K: 3.3 V IO, 1.8 V bank 0; ESP32: 3.3 V IO).
- Always note when a wiring change carries risk of damaging hardware.
- Document every known hardware mistake in about.md so others avoid it.
- Do not submit bitstreams or sketches that have not been verified on real
  hardware unless clearly marked `UNTESTED`.

## Contribution Guidelines

- All RTL changes must pass `synlig` synthesis with zero ERRORs before PR.
- All RTL changes must pass `nextpnr` place-and-route with PASS timing.
- Hardware-verified results must include the exact serial output as proof.
- Update `continue.md` and `about.md` when any behaviour changes.
- Keep commit messages short and imperative: `fix: PRESENT exit overrides last input`.

## Enforcement

Instances of unacceptable behaviour may be reported by opening an issue
marked `[conduct]`. All complaints will be reviewed and investigated and
will result in a response deemed necessary and appropriate to the circumstances.
Maintainers who do not follow or enforce the Code of Conduct may be removed
from the project.

## Attribution

This Code of Conduct is adapted from the
[Contributor Covenant](https://www.contributor-covenant.org), version 2.1.
