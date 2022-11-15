# 사용법

NetModule 에서 Prism 을 이용해 Singleton 으로 등록된 DDSService Singleton Instance 를 DI 로 받는다.

DDSService 는 Listener 와 Write 관련 함수가 있으며 이것만 사용하면 된다.

## What should be edited depend on Project

```DDSService``` 에서 ```DDSManager``` 생성하는 부분에서 LibraryName, ProfileName 등

```DDSManager QOS.cs```
+ Writer/Reader 에서 사용할 ```<Type, QOS_Name>``` Dictionary 를 틍록해주어야한다.
+ 등록시 하드코딩된 ```QOS_Profile_Name``` 를 바꿔준다.

MainWindow 가 실행되는 프로젝트 등에 PostBuild Event 에 ```USER_QOS_PROFILES.xml``` 를 실행파일이 있는 경로에 복사하는 코드를 넣는다.



# Structure

## NetModule 

Singleton 으로 DDSService 생성

## DDSService

+ DDSManager 를 생성하는 역할
+ ```Dictionary<Type, List<IDisposable>> SubscribedDDSObservable``` 을 통해 Reactive 기반 Listener 구현
+ ```Write()``` 래퍼
+ Prism 으로 Singleton Instance 를 생성하고 DI 로 이것을 얻어서 사용함.

## DDSManager

+ ```DomainParticipant```, ```Publisher```, ```Subscriber``` 를 하나씩 두고 Type 별로 ```DataWriter```, ```DataReader``` 를 생성하는 방식
+ ```PostProcessing``` 는 Write 할 때 값 전처리용 함수가 들어있다.
+ ```Type``` 별로 Data Reader/Writer 를 저장하는 Dictionary 를 이용해 Pooling Pattern 을 사용한 Get/Set 을 할 수 있다.
  + ```DDSManager QOS.cs``` 에서 정의한 함수로 만들어놓은 ```DataWriterQoSDic```, ```DataReaderQoSDic``` 를 이용해 없는경우 생성해준다.
  + Writer 의 경우 미리 생성해주는 듯.

### Topic

```DDSManager``` 가 Reader/Writer 생성할 때 Type 을 보고 Topic 생성. 이때 Type Regist 도 같이 해준다.

### DataReader

Reactive 에서 제공하는 Observer Pattern 을 이용해 Connect an Event of Listener with an User Event

```DataReaderRx``` 에 기본적인 구현이 있다. ```DataReader``` 는 ```DDSService``` 가 준비되지 않았을 때 기능을 끄는 추가적인 역할을 위해 만든 듯.

```Reactive.Sample``` 때문에 ```Dispose()``` 필요

#### DataListener

```on_data_available``` 만 쓰는 듯.





# 의문?

```DataReaderRx``` 생성자에서 libraryName 없는데 왜 ```CreateDataReaderWithProfile()``` 로 먼저 생성해서 버그를 굳이 만드는지?


