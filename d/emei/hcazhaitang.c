//Room: hcazhaitang.c ������ի��
//Date: Oct. 2 1997 by That

inherit ROOM;
string* names = ({
        __DIR__"obj/mala-doufu",
        __DIR__"obj/bocai-fentiao",
        __DIR__"obj/shanhu-baicai",
        __DIR__"obj/liuli-qiezi",
});

void create()
{
      set("short","������ի��");
      set("long",@LONG
������Ƕ��һ����ֵ�ի�á�ի��������˳����Ĳ����ͳ��ʣ���λС
ʦ̫������æµ�Ų�����ի�����ϰ��˼��趹��������������Լ���Ѽ����
ζ��ʳ��ի�ú�����һ����ͨ�������ִ���䣬���ߵ�����ͨ��㳡��
LONG);
      set("exits",([ /* sizeof() == 1 */
          "south" : __DIR__"chuwujian", 
          "north" : __DIR__"hcaeast2", 
      ]));

      set("objects",([
           __DIR__"obj/qingshui-hulu" : 1,
           names[random(sizeof(names))]: 1,
           names[random(sizeof(names))]: 1,
           names[random(sizeof(names))]: 1,
      ]));
//      set("no_clean_up", 0);
      setup();
      replace_program(ROOM);
}
