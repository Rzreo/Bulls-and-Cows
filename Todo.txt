# Connect

Client 가 ClientID 로 먼저 Connect 함.
+ Connect 성공시
   + Server 가 Connect 성공했다고 메시지를 줌.
   + Server 가 Client 에게 Joinable Room List 를 보내줌. 아마 텍스트파일?
+ Client 에서 QOS Time Out 구현

Server 는 Client 에 CLIENT_CONNECT_[ClientID] 토픽으로 결과를 보내줌. 
+ CLIENT_CONNECT 는 string 하나만 있어서 스트링 분기검사해서 처리
+ 그리고 이후 Client 요청에 대한 피드백도 여기로 해줌. 
+ 피드백 리스트는 idl 에 상수로 적어놓기


# 방 들어가기

Client 가 방을 만듬
+ 총 인원 N <= 8 명의 방을 만드는 메시지를 서버에 보냄
+ CLIENT 와 비슷하게 ROOM_STATE_[RoomID] 토픽과 ROOM_MESSAGE_[RoomID] 토픽을 생성
  + ROOM_STATE 에는 
     + ROOM_ID
     + MAX_PARTICIPANT
     + 8 개의 현재 참석중인 CLIENT_ID
     + 틀린 갯수
  + ROOM_MESSAGE 에는 string 하나 넣어서 분기처리
+ Server 는 연결된 Client 에게 방 추가되었다고 알려줌

Client 가 이미 있는 방에 들어감
+ Joinable Room List 에 있는 방 번호가 있는 메시지를 클라가 서버에 보냄.

공통적으로 서버는 CLIENT_CONNECT 로 클라에게 방에 들어가라고 함.



# 게임 진행

서버는 클라이언트에게 게임시작했다고 가능한 게임방목록에서 제거해줌.

클라이언트는 서버에 CLIENT_CONNECT 로 인풋전달

서버는 결과로 ROOM_MESSAGE_[RoomID] 로 전달

서버랑 클라는 각각 결과물 저장해서 표시



# 게임 종료

서버가  ROOM_MESSAGE_[RoomID]  로 겜 끝낫다고 전달

