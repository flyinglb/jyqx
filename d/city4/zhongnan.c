//  Room:  /d/city4/zhongnan.c
//cglaem...12/12/96.

inherit  ROOM;

void  create  ()
{
    set  ("short",  "����ɽ��");
    set  ("long",  @LONG
����ɽ�ֳ�̫��ɽ���೤���ǰ�ʮ������С������������
����֮˵���ݴ���������ɽ�н�����������ٵ���Խ����ɽ�ڣ���
��������ƣ�����ȴû��һ��·������ɽ���������������Ĵ����
����ǰ����ԭ��
LONG);
    set("exits",  ([  /*  sizeof()  ==  4  */
        "east"  :  __DIR__"road2",
        "west"  :  __DIR__"road3",
    ]));
    set("outdoors",  2);

    setup();
}






