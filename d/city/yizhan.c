//Room of wizard that haven't modify own workroom.
//Modify by Super 1998.1.2

inherit ROOM;

void create()
{
         set("short","��վ");
        set("long",@LONG
ר��Ϊ�������ŵĵط�,��Ϊ���ȴ����,����ʮ�ֻ�ӭ
�д򹤵�������æ,��Ȼ�ô���һ���е�.ǽ�Ϲ���һ����Ŀ
�ĸ�ʾ(gaoshi).
LONG);
        set("item_desc", ([
           "gaoshi" : "Ǳ�ܳ����������*10��,��������Ǳ�ܻή������*10.�ش�֪ͨ.\n",
       ]));
          set("exits",([
                    "west" : "/d/city/beimen",
                   ]));
           set("objects",([
                       __DIR__"npc/zongguan" : 1,
                   ]));
        set("no_fight", "1");
        set("no_clean_up", 0);
setup();
}
