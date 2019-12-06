//Room of wizard that haven't modify own workroom.
//Modify by Super 1998.1.2

inherit ROOM;

void create()
{
         set("short","驿站");
        set("long",@LONG
专门为人们送信的地方,因为最近却人手,所以十分欢迎
有打工的人来帮忙,当然好处是一定有的.墙上挂着一张醒目
的告示(gaoshi).
LONG);
        set("item_desc", ([
           "gaoshi" : "潜能超过你的悟性*10者,做此任务潜能会降回悟性*10.特此通知.\n",
       ]));
          set("exits",([
                    "north" : __DIR__"westgate",
                   ]));
           set("objects",([
                       "/d/city/npc/zongguan" : 1,
                   ]));
        set("no_fight", "1");
        set("no_clean_up", 0);
         replace_program(ROOM);
setup();
}
