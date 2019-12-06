// by enter
// modified by wind

inherit ROOM;

int begin_diao(object fir,object sec);
void create()
{
        set("short", "����ͤ");
        set("long", @LONG
������һ��������Сͤ�ӣ��Ҷ���д�š�����ͤ����һ����֪����
�����ǵ����߳����ĵط�����������Ͳ���˵�ж����ˣ����������
�����㣬���ǿ��Ժúñ�һ���ˡ�(����������diao��)
LONG
        );
       set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"diaoyuchi",
]));
      set("no_fight",1);
        setup();
}
void init()
{
 add_action("do_diao", "diao");
}

int do_diao()
{
       object *list;
         object me;
         object fir,sec,where;
       int d = 0;
       int j;
    me=this_player();

   if (me->query("combat_exp") >= 10000 )
   return notify_fail("�������Ѿ�����ͨ���������Ӿ����ˡ� \n");
   if (me->query("potential") - me->query("learned_points") >= 300 )
   return notify_fail("�������Ѿ�����ͨ����������Ǳ���ˡ� \n");

    me->set_temp("diao/ready",1);

    list = users();
    j = sizeof(list);
    while( j-- )
      {
          // Skip those users in login limbo.
        if( !environment(list[j]) ) continue;
        if( !me->visible(list[j]) ) continue;

       where = environment(list[j]);
       if((string)where->query("short")!="����ͤ") continue;
        if ((int)list[j]->query_temp("diao/ready")){
            if(d==0)
             fir=list[j];
          if(d==1)
             sec=list[j];
          d++;
           }
       }
       if(d>2){
         return notify_fail("������ʱֻ���������˱��������ԣ���������һ���������\n");
         }
       if(d==2){
         return begin_diao(fir,sec);
         }
         else{
         message_vision("$P�Ѿ�׼���õ����ˣ���˭Ҫ����������\n",me);
           return 1;
       }
}
int valid_leave(object me, string dir)
{
       me->set_temp("diao/ready",0);
         message_vision("$P����߷��˻�ȥ.\n",me);
       return ::valid_leave(me, dir);
}

int begin_diao(object fir,object sec)
{
 int i,firfu,secfu,comba;
// string fishsname;
// int fishsfactor;
 //  ���㣬���㣬�޷ǣ��ײ������������㣬���㣬����㣬����
 // fishsfactor[0]=39;
 if(fir->query("qi")<10||sec->query("qi")<10)
     return notify_fail("С�����壬��Ҫ����������������ˣ�\n");
 if(fir->is_busy()||sec->is_busy())
     return notify_fail("��û��������أ�\n");
 fir->start_busy(3);
 sec->start_busy(3);

 firfu=random(fir->query("int")*2);

 for(i=13;i>=5;i--)
   if(firfu>=i*3) break;
 message_vision("ֻ����Ưһ����$Pæ��һ�ո�.\n",fir);
 if(i<5){
   call_out("no_fish",4,fir);
 }
 else{
   call_out("one_fish",5,fir,i);
 }
 secfu=random(sec->query("int")*2);

 for(i=13;i>=5;i--)
   if(secfu>=i*3)break;
 message_vision("ֻ����Ưһ����$Pæ��һ�ո�.\n",sec);
 if(i<5){
   call_out("no_fish",4,sec);
 }
 else{
   call_out("one_fish",5,sec,i);
 }

 if(secfu>firfu){
    if(sec->query("combat_exp")>10000) {
      return notify_fail("�����Ѿ������ˣ����Ծ����Ǳ�ܻ����ұ����ɣ�\n");
   }


   message_vision("��һ�غ�$P��$p��ˮƽ�ߣ�����Ӧ�õõ�������\n\n",sec,fir);
   message_vision("$P�õ���"+chinese_number(secfu/3)+"�㾭��\n",sec);
   comba=sec->query("combat_exp");
   comba+=secfu/3;
   sec->set("combat_exp",comba);
   message_vision("$P�õ���"+chinese_number(secfu/5)+"��Ǳ��\n",sec);
   comba=secfu/5;
   comba+=(int) sec->query("potential");
   sec->set("potential",comba );
 }
 if(secfu<firfu){
   if(fir->query("combat_exp")>10000){
     return notify_fail("�����Ѿ������ˣ����Ծ����Ǳ�ܻ����ұ����ɣ�\n");
   }

   message_vision("$P��$p��ˮƽ�ߣ�����Ӧ�õõ�������\n\n",fir,sec);
   message_vision("$P�õ���"+chinese_number(firfu/4)+"�㾭��\n",fir);
   comba=fir->query("combat_exp");
   comba+=firfu/4;
   fir->set("combat_exp",comba);
   message_vision("$P�õ���"+chinese_number(firfu/6)+"��Ǳ��\n",fir);
   comba=firfu/6;
   comba+=(int) fir->query("potential");
   fir->set("potential",comba );
 }
 if(secfu==firfu)
 message_vision("��һ�غ�$P��$p��ˮƽһ�������ԾͲ��ط����ˣ�\n",fir,sec);
 sec->receive_damage("qi",20);
 fir->receive_damage("qi",20);
 return 1;
}
private void bouns(object fir,object sec)
{
}
private void no_fish(object fir)
{
   message_vision("����$Pû���򵽵���Ĺؼ�.\n",fir);
   message_vision("$P����û�е����㣬�����������û��.\n",fir);
}
private void one_fish(object fir,int i)
{
  string fishsname;
   if(i==13)fishsname="����";
   if(i==12)fishsname="����";
   if(i==11)fishsname="�޷���";
   if(i==10)fishsname="�ײ���";
   if(i==9)fishsname="������";
   if(i==8)fishsname="����";
   if(i==7)fishsname="����";
   if(i==6)fishsname="�����";
   if(i==5)fishsname="����";

   message_vision("$P������һ��"+fishsname+".\n",fir);
   message_vision("$P��ʼ�������.\n",fir);
}
