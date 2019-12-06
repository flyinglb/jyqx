//Room: /d/mingjiao/fangtang.c

inherit ROOM;
string* names = ({
        "/d/emei/obj/mala-doufu",
        "/d/emei/obj/bocai-fentiao",
        "/d/emei/obj/shanhu-baicai",
        "/d/emei/obj/liuli-qiezi",
        "/d/hangzhou/npc/obj/fish",
        "/d/hangzhou/npc/obj/pork",
        "/d/hangzhou/npc/obj/shrimp",
        "/d/hangzhou/npc/obj/geng",
        "/d/hangzhou/npc/obj/chicken",
        "/d/hangzhou/npc/obj/baozi",
});

void create()
{
      set("short","���̷���");
      set("long",@LONG
����������̵ķ��á������˳����Ĳ����ͳ��ʣ���λ�����
��������æµ�Ų��á����ϰ��˼��趹��������������Լ����㣬
���⣬�����Ƶ���ζʳ�����ߵ�����ͨ��㳡��
LONG);
      set("exits",([ /* sizeof() == 1 */
          "east" : __DIR__"square", 
      ]));

      set("objects",([
          "/d/hangzhou/npc/obj/jiuping": 1,
           names[random(sizeof(names))]: 1,
           names[random(sizeof(names))]: 1,
           names[random(sizeof(names))]: 1,
           names[random(sizeof(names))]: 1,
           names[random(sizeof(names))]: 1,
      ]));
//      set("no_clean_up", 0);
      setup();
      replace_program(ROOM);
}
