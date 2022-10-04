# edoc22-2
#github에서 올리기
## 1. 개인 노트북에서 코드 작성

## 파일 이름 형식 : 학번_문제번호

![image](https://user-images.githubusercontent.com/112494061/193885879-bb82210b-6386-4a95-b149-63c494690c5c.png)


# 2. edoc22-2 레포에서 개인 브랜치 선택

## 브랜치 형식 : 영문이름

### ex) BaeYunJu

![image](https://user-images.githubusercontent.com/112494061/193886102-131eeba7-7cec-4a13-9c41-96cd400fad07.png)


### 혹시나 브랜치를 선택했을 때 폴더가 없는 경우 기존 브랜치를 삭제하고 새로 생성해주세요!!

## 예시)

![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/c776cd5e-cf04-4553-bc39-318ebb5f63db/Untitled.png)

→ 위와 같이 현재 사용할 폴더가 없는 경우 브랜치를 새로 만들어야 합니다!

![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/81126c11-8605-4f29-9a12-21c0153529b4/Untitled.png)

브랜치 이름 옆 branch로 들어가시면 본인이 생성한 브랜치를 확인할 수 있습니다. 

삭제하시고 다시 브랜치를 만들어주세요!

# 3. 날짜와 레벨을 선택해서 파일 업로드

### 브랜치가 자신의 것인지 꼭 확인해주세요!

![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/54df639b-64d4-4839-a7fd-413b10e8458e/Untitled.png)

![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/84095fa4-b7c1-42f8-82c6-f49fa4a611cf/Untitled.png)

![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/6da8c72e-32ce-4efe-9813-664f713c16fb/Untitled.png)

자신의 브랜치에서 파일이 잘 올라갔는지 확인해주세요!

# 4. pr 날리기

## 성공/실패 모두 pr 날려주세요!

## pr형식 : [성공/실패] 날짜_레벨_이름(조)

예시 : [성공] 0928_초중급_배윤주(5)

![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/cc195a4e-7747-48cc-a911-35f53ace3e4a/Untitled.png)

![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/f58a8217-d443-4a23-be29-adb7b027e256/Untitled.png)

- 이 화면에서 base :  main ← compare : main이라고 돼 있는 부분을 compare : 자신의 브랜치로 바꿔주세요

![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/0cb23b8f-48b2-44b0-a5a5-46ee4088e0cb/Untitled.png)

- 자신의 브랜치에서 변경이 생겼으면 자동으로 compare & pull request가 뜨니 이 버튼을 누르셔도 되고 new pull request 누르신 후 브랜치 main에서 자신의 브랜치로 바꿔서 pr날려주셔도 됩니다!

![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/c2f8f99c-738c-443c-b156-5767bb2b07c9/Untitled.png)

### pr 형식 꼭 지키셔서 날려주세요!

### 성공/실패 여부 이미지를 포함시켜 주세요! 화면 캡쳐하시고 바로 붙여넣기 하시면 자동으로 생성됩니다!

![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/341ffc7f-9824-4230-afe9-a4b02c124e24/Untitled.png)

pull request 창에 자신의 pr이 잘 올라갔는지 확인해주세요!
# CLI
## 초기 설정하기
원하는 로컬 위치에서 clone(다운로드) 받기
```
git clone https://github.com/edoc14/edoc22-2.git
```

—
### edoc22-2 폴더 내에서
원격 레포 pull 받기 - 이때 커밋하지 않은 변경사항이 없도록 해주세요
```
git pull
```
브랜치 바꾸기(이미 만들어진 브랜치는 -b 옵션 없이 입력)
```
git chechout -b "<branch_name(본인 영문 이름)>"
```
코드 작성 완료 후
```
git add <파일 이름> # 특정 파일 올리기
git add .         # 모든 변경사항 올리기
```
커밋 메세지 작성 & 커밋하기
```
git commit -m "<commit message>"
```
원격 레포지토리에 push하기
```
git push
```
