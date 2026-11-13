# OSS Team Project Piano

#English
A virtual piano team project written in C using raylib. The current test program opens a window that displays `Hello, raylib!` so team members can verify their development setup.

## Build and Run on Windows

### Prerequisites

- Git and SourceTree
- Visual Studio Code with Microsoft's **C/C++** and **CMake Tools** extensions
- Visual Studio or Visual Studio Build Tools with the **Desktop development with C++** workload
- CMake 3.22 or later. If you use the Visual Studio 2026 generator, use CMake 4.2 or later.

### Build and Run

1. Clone this repository using SourceTree.
2. Open the folder containing `CMakeLists.txt` in VS Code.
3. Press `Ctrl+Shift+P` and run **CMake: Configure**. If prompted to select a compiler, choose the Visual Studio MSVC toolchain.
4. Press `Ctrl+Shift+P` and run **CMake: Build**.
5. Select the `piano` target in the CMake Tools panel and run it. The setup is working when the window displays `Hello, raylib!`. Press `Esc` to close it.

CMake downloads raylib 6.2 from GitHub during the initial configuration. You need an internet connection for this step. A separate raylib installation is optional.

## Team Workflow

1. Pull the latest changes on `main`, then create a branch for your work, such as `feature/audio` or `feature/record`.
2. Commit your changes, push your branch, and open a pull request targeting `main`.
3. Add new `.c` files to `src/` and list them under the `piano` target in `CMakeLists.txt`. Keep `build/` and generated executables out of commits.


#Korean

C와 raylib으로 만드는 가상 피아노 팀 프로젝트입니다. 현재 테스트 버전에서는 `Hello, raylib!` 창을 띄워 개발 환경을 확인할 수 있습니다.

## Windows에서 빌드하기

### 준비물

- Git 또는 Git이 포함된 SourceTree
- VS Code와 Microsoft의 **C/C++**, **CMake Tools** 확장
- Visual Studio 또는 Build Tools의 **C++를 사용한 데스크톱 개발** 워크로드
- CMake. Visual Studio 2026을 사용하면 CMake 4.2 이상이 필요합니다.

### 빌드 및 실행

1. SourceTree에서 이 저장소를 **Clone**합니다.
2. VS Code에서 `CMakeLists.txt`가 있는 폴더를 엽니다.
3. `Ctrl+Shift+P` → **CMake: Configure**를 실행합니다. 컴파일러 선택 화면이 나오면 Visual Studio의 MSVC를 선택합니다.
4. `Ctrl+Shift+P` → **CMake: Build**를 실행합니다.
5. CMake 패널에서 `piano`를 실행합니다. `Hello, raylib!` 창이 뜨면 성공입니다. `Esc`로 닫을 수 있습니다.

첫 구성 때 CMake가 GitHub에서 raylib 6.2를 자동으로 받아 빌드합니다. 이 단계에는 인터넷 연결이 필요합니다.

## 팀 작업 방법

1. SourceTree에서 `main`을 **Pull**한 뒤 `feature/audio`, `feature/record`처럼 기능별 브랜치를 만듭니다.
2. 변경 사항을 **Commit → Push**하고, GitHub에서 `main`으로 **Pull Request**를 올립니다.
3. 새 `.c` 파일은 `src/`에 추가하고 `CMakeLists.txt`의 `piano` 빌드 목록에 등록합니다. `build/`와 실행 파일은 커밋에서 제외합니다.





