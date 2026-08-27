# LEARN: Project Usage

문서 유형: 학습용

이 저장소는 Visual Studio 솔루션 하나에 여러 C++ 프로젝트를 붙이는 방식으로 사용합니다.

## 기본 원칙

```text
솔루션 1개 = AlgorithmStudy
프로젝트 1개 = 챕터 1개
```

예:

```text
Chapter01_Basics
Chapter02_Array
Chapter03_String
Chapter04_StackQueue
Chapter05_Graph
```

## 새 챕터 추가

Visual Studio에서 다음 순서로 추가합니다.

```text
Solution 우클릭
  -> Add
  -> New Project
  -> C++ Empty Project
  -> Project name: ChapterXX_Name
  -> Location: AlgorithmStudy/chapters
```

그 다음 프로젝트에 `.cpp`, `.h`, `.hpp` 파일을 추가해서 풀이를 작성합니다.

## Git 사용 기준

여러 컴퓨터에서 이어서 공부하기 위해 GitHub에 올립니다.

커밋은 너무 거창하게 하지 않아도 됩니다.

```text
solve: add array basics practice
docs: add chapter 01 notes
refactor: clean up stack examples
```
