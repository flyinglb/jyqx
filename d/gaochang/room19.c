inherit ROOM;
void break_b(object me);
void create()
{
    set("short", "��ľ��");
    set("long", @LONG
����һ����Լ�ߴ�Ķ�ľ��(bridge)������������������½�ͷ����ɣ�
ֻҪһ��������һʧ�㣬���̱�Ҫ������ǡ����������Լ����ʮ���ɣ���
�¿����ͱ��絶�����ƾ���ӿ������ף�Ͷ��ʯ����ȥ��Ҳ������������
LONG
    );
    set("exits", ([ 
  "south" : __DIR__"room18",
  "north" : __DIR__"room20",
]));
        set("item_desc",([
    "��ľ��":"    һ����Լ�ߴ�Ķ�ľ�ţ�����ֻ�ܹ�һ���ˡ�\n",
    "bridge":"    һ����Լ�ߴ�Ķ�ľ�ţ�����ֻ�ܹ�һ���ˡ�\n",
    ]));

    setup();
}
void init()
{
    object me=this_player();
    object room,*obj;
    int i;
    if (wizardp(me)) return;
    if (!room=find_object(__DIR__"room18"))
         room=load_object(__DIR__"room18");
// �ж��ŵ���һ�䷿��OBJ
    obj=all_inventory(room);
    if (sizeof(obj))
    for (i=0;i<sizeof(obj);i++){
         if (obj[i]->is_character() && !obj[i]->is_corpse() ) 
        {
          break_b(me);
          room->break_b(obj[i]);
          return;
        }
     }
// �ж���䷿��OBJ
    obj=all_inventory(this_object());
    if (!sizeof(obj)) return;
    for (i=0;i<sizeof(obj);i++){
         if (obj[i]==me) continue;
         if (obj[i]->is_character() && !obj[i]->is_corpse() ){
          break_b(me);
          break_b(obj[i]);
          return;
        }
     }
    
}
void down_die(object me)
{
    if (me)  me->die();
}
void break_b(object me)
{
    object room=find_object(__DIR__"room50");
    if (wizardp(me)) return;
    if (random(10)<5){
    if (!room)
      room=load_object(__DIR__"room50");
    message_vision("��ľ�Ŷ��ˡ�$N�Һ�һ�������¾��¡�\n",me);
    me->set_temp("die_for","���¾���ˤ");
    me->move(room);
    message("vision",me->name()+"�Һ�һ��������������\n",room,({me}));
        if((int)me->query("qi")<1000) call_out("down_die",1,me);
        else {
    me->receive_damage("qi", 1000);
    me->receive_wound("qi", 1000);
    me->unconcious();
    }
    }else
    {
    if (!(room=find_object(__DIR__"room74")))
      room=load_object(__DIR__"room74");
    message_vision("Σ�Ŷ��ˡ�$N�Һ�һ�������¾��¡�\n",me);
    me->set_temp("die_for","���¾���ˤ");
    me->move(room);
    message("vision",me->name()+"�Һ�һ��������������\n",room,({me}));
    }
}
