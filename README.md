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

![image](https://user-images.githubusercontent.com/112494061/193886215-86c22d1b-a551-41cf-b1cb-dd0dc83180e2.png)

→ 위와 같이 현재 사용할 폴더가 없는 경우 브랜치를 새로 만들어야 합니다!

![image](https://user-images.githubusercontent.com/112494061/193886549-7afb3a9d-202a-4f23-8c06-932245deb5a5.png)

브랜치 이름 옆 branch로 들어가시면 본인이 생성한 브랜치를 확인할 수 있습니다. 

삭제하시고 다시 브랜치를 만들어주세요!

# 3. 날짜와 레벨을 선택해서 파일 업로드

### 브랜치가 자신의 것인지 꼭 확인해주세요!

![image](https://user-images.githubusercontent.com/112494061/193886301-95693854-9925-4396-80bb-8b6842a40b84.png)

![image](https://user-images.githubusercontent.com/112494061/193886321-bf58bfd7-df5d-442f-a346-5710f344c23a.png)


자신의 브랜치에서 파일이 잘 올라갔는지 확인해주세요!

# 4. pr 날리기

## 성공/실패 모두 pr 날려주세요!

## pr형식 : [성공/실패] 날짜_레벨_이름(조)

예시 : [성공] 0928_초중급_배윤주(5)

![image](https://user-images.githubusercontent.com/112494061/193886358-51169fcf-89ac-4c6e-a90a-8abe9e8b1abb.png)


- 이 화면에서 base :  main ← compare : main이라고 돼 있는 부분을 compare : 자신의 브랜치로 바꿔주세요

![image](https://user-images.githubusercontent.com/112494061/193886396-55557d81-7435-435e-a1db-6c7bf0c5cde5.png)

- 자신의 브랜치에서 변경이 생겼으면 자동으로 compare & pull request가 뜨니 이 버튼을 누르셔도 되고 new pull request 누르신 후 브랜치 main에서 자신의 브랜치로 바꿔서 pr날려주셔도 됩니다!
- 
![image](https://user-images.githubusercontent.com/112494061/193886417-c4c1c2ae-50b6-4088-9d2f-21a0680503ed.png)

### pr 형식 꼭 지키셔서 날려주세요!

### 성공/실패 여부 이미지를 포함시켜 주세요! 화면 캡쳐하시고 바로 붙여넣기 하시면 자동으로 생성됩니다!

![image](https://user-images.githubusercontent.com/112494061/193886449-178b44e7-d9de-48c7-8de0-f07ac502db37.png)

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
