# AlgorithmStudy

Visual Studio 기반 알고리즘 학습용 저장소입니다.

## 구조

```text
AlgorithmStudy/
  AlgorithmStudy.sln
  chapters/
    ChapterTemplate/
      ChapterTemplate.vcxproj
      main.cpp
      ProblemTemplate.hpp
      ProblemTemplate.cpp
      README.md
  docs/
```

## 사용 방식

챕터 하나를 Visual Studio 프로젝트 하나로 관리합니다.

```text
ChapterTemplate = 새 챕터를 만들 때 참고할 기본 프로젝트
```

새 챕터를 만들 때는 Visual Studio에서:

```text
Solution 우클릭
  -> Add
  -> New Project
  -> C++ Empty Project
  -> Location: chapters/ChapterXX_Name
```

각 챕터 프로젝트 안에 필요한 `.cpp`, `.h`, `.hpp` 파일을 직접 추가해 풀이를 채웁니다.

## 기록 방식

문제 풀이를 GitHub에 올리는 목적은 코드 백업과 여러 컴퓨터 간 동기화입니다.

정리된 풀이만 남기고 싶다면 챕터별 `README.md`에 다음 정도만 기록합니다.

```text
문제 유형
핵심 아이디어
시간복잡도
공간복잡도
다시 볼 포인트
```
