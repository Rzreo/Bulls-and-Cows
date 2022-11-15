# Config

PostBuild Event 에 Test.Configuation 에 있는 데이터를 실행파일이 있는 곳으로 복붙하는 코드가 있다. 
+ 여기서 ```USER_QOS_PROFILES.xml``` 가 들어가게 된다.
+ 또한 c++ clr 로 만들어진 Types 관련 프로젝트가 실행되기 위해서 필요한 c dds 관련 dll 도 복사해준다.(아님 직접 복붙)