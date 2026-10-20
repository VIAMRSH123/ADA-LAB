# Daily Commit Backlog

ADA-LAB is **submitted coursework** (Analysis & Design of Algorithms, C) and a public portfolio. It was
graded, so work here is **additive and documentary**. A scheduled Claude Code agent takes the **top
unchecked item**, does it properly, verifies it, and commits.

## Rules

1. **One item per run.** Finish it or leave it uncommitted.
2. **ALLOWED:** READMEs (per lab and a top-level index), `.gitignore` entries, an environment note so
   the notebook runs, dataset provenance/licence notes, removal of clearly accidental junk.
3. **FORBIDDEN:** rewriting or "improving" a lab solution, changing an algorithm or its output,
   re-running the notebook so stored outputs change, reformatting submitted source. If a lab looks
   wrong, record it under *Observations* below. Never silently fix it.
4. **Verify.** A README may only describe what the code does, and every command it tells a reader to
   run must actually have been run. Confirm no `.c`/`.ipynb` file changed.
5. **No filler.** No whitespace churn, comment padding, or substance-free docs edits. If nothing can be
   done honestly, make no commit.
6. Stage named paths only (never `git add -A` / `.`). Conventional commit subject. Tick the item and
   append to the Log in the same commit.

---

## Queue

- [ ] **R1 - Top-level `README.md`.** Index of Labs 1-6 plus `DEV/`: topic, file, what it
      demonstrates, how to build (`gcc "<file>.c" -o out`), and the licence. Currently the repo has no
      README at all. Verified facts to use: Lab 1 = two LeetCode solutions (stack/queue, no `main`);
      Lab 2 = selection sort with timing; Lab 3 = merge sort with timing; Lab 4 = quick sort with
      timing; Lab 5 = Prim's MST on a fixed 5-vertex matrix; Lab 6 = Dijkstra and 0/1 knapsack (DP).
- [ ] **R2 - `Lab 1/README.md`.** The two files have no `main` or `#include`; they are LeetCode
      submissions (946 Validate Stack Sequences, 1944 queue problem) and will not compile standalone.
      Say so, and give a tiny driver snippet in the README (not in the source) if it can be run.
      Note the file named "1944 Number of Visible People in a Queue" actually implements the
      sandwich/students problem (LeetCode 1700); see Observations.
- [ ] **R3 - Sorting labs README (Labs 2, 3, 4).** Menu options (1 manual entry, 2 timing sweep
      N=500..14500 step 1000 on reverse-sorted input, 3 exit), time complexity, and what the committed
      graphs/PDFs/PNG show. Describe the graph files only after opening them.
- [ ] **R4 - Graph labs README (Labs 5, 6).** Input format for Prim's (5x5 matrix, 0 = no edge),
      Dijkstra (n, matrix with 9999 = infinity, source), and knapsack (n, weight/value pairs, capacity).
      Include a worked example whose output was actually produced by compiling and running the code
      (Prim's 5x5 example gives total cost 16; knapsack weights 2,3,4 / values 3,4,5 / cap 5 gives 7).
      Reference the screenshots `Dijkstra.png` and `Knapsack.png` after viewing them.
- [ ] **R5 - `DEV/README.md` + `requirements.txt` for `DevAAT.ipynb`.** The notebook is an air-quality
      EDA (cleaning, AQI trends, correlation heatmap, plotly scatter). It reads `/city_day.csv`,
      `/city_hour.csv`, `/station_day.csv`, `/station_hour.csv`, `/stations.csv` from the filesystem
      root, and the stored output shows `FileNotFoundError`, so the notebook has never run
      successfully in its committed state. Document the five expected files, their origin (the data
      looks like the Kaggle "Air Quality Data in India" set; **confirm and record the licence, do not
      assume**), and a requirements file for pandas, numpy, matplotlib, seaborn, plotly (versions seen
      in the output: pandas 2.2.2, numpy 2.0.2, matplotlib 3.10.0, seaborn 0.13.2). Do not edit the notebook.
- [ ] **R6 - `.gitignore`** for compiled binaries (`a.out`, `*.exe`, `*.o`), `.DS_Store`,
      `.ipynb_checkpoints/`, editor folders, and the notebook's generated `city_day_cleaned.csv`.
      Do this only with a reason; nothing of the kind is tracked today.
- [ ] **R7 - Add a build check note.** Compile all labs with `gcc -Wall` and record in the README
      which warnings are expected (see Observations) so a reader is not surprised. Doc only.

## Observations (for VB to decide; do NOT fix as part of the daily agent)

- **Lab 4 `Quick Sort.c` segfaults.** `main` declares a local `int a[8]` that shadows the global
  `a[15000]`. The timing loop then writes `a[i]` for i up to 14499 into the 8-element local array
  (confirmed with `-fsanitize=address`: stack-buffer-overflow; plain build exits 139 and prints
  nothing because stdout is buffered). The `quickSort`/`partition` logic itself is fine. The graded
  version is unchanged; a fix would be to rename the local array or drop the shadowing.
- **Lab 1 filename/problem mismatch.** `1944.Number of Visible People in a queue.c` contains
  `countStudents` (LeetCode 1700, Number of Students Unable to Eat Lunch).
- **Labs 2 and 3 use `void main()`** (gcc `-Wmain` warning) and an unused `temp` assigned in a
  "dummy delay" loop; the delay loop inflates the reported timing, so absolute numbers in the
  committed graphs include artificial delay (500000 iterations in Lab 2, 5000000 in Lab 3).
- **`DEV/DevAAT.ipynb` vs the `DEV-AAT` / `dev` repos** look like the same air-quality EDA.
  VB to decide whether to consolidate; the agent must not merge or delete anything.
- Notebook default `fillna(method=...)` on a groupby is deprecated in pandas 2.x; noted only.
- Dijkstra uses a fixed 100x100 matrix and does not validate `n` or `src`; Prim's assumes a connected graph.

---

## Log

Append one line per commit: `YYYY-MM-DD - <item id> - <commit subject>`.

- 2026-10-20 - audit - docs: add commit backlog and audit notes for ADA-LAB
