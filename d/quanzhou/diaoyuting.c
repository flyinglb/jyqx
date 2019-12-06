// by enter
// modified by wind

inherit ROOM;

int begin_diao(object fir,object sec);
void create()
{
        set("short", "钓鱼亭");
        set("long", @LONG
这里是一个靠湖的小亭子，匾额上写着“钓鱼亭”，一看就知道，
这里是钓鱼者常来的地方，鱼池里的鱼就不用说有多少了！如果两个人
来钓鱼，可是可以好好比一比了。(可以在这里diao鱼)
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
   return notify_fail("你现在已经不能通过钓鱼增加经验了。 \n");
   if (me->query("potential") - me->query("learned_points") >= 300 )
   return notify_fail("你现在已经不能通过钓鱼增加潜能了。 \n");

    me->set_temp("diao/ready",1);

    list = users();
    j = sizeof(list);
    while( j-- )
      {
          // Skip those users in login limbo.
        if( !environment(list[j]) ) continue;
        if( !me->visible(list[j]) ) continue;

       where = environment(list[j]);
       if((string)where->query("short")!="钓鱼亭") continue;
        if ((int)list[j]->query_temp("diao/ready")){
            if(d==0)
             fir=list[j];
          if(d==1)
             sec=list[j];
          d++;
           }
       }
       if(d>2){
         return notify_fail("这里暂时只能让两个人比赛，所以，请过多的人一会儿再来。\n");
         }
       if(d==2){
         return begin_diao(fir,sec);
         }
         else{
         message_vision("$P已经准备好钓鱼了，有谁要和他比试吗？\n",me);
           return 1;
       }
}
int valid_leave(object me, string dir)
{
       me->set_temp("diao/ready",0);
         message_vision("$P把渔具放了回去.\n",me);
       return ::valid_leave(me, dir);
}

int begin_diao(object fir,object sec)
{
 int i,firfu,secfu,comba;
// string fishsname;
// int fishsfactor;
 //  鲤鱼，鲫鱼，罗非，白昌，虹鳟，莲鱼，草鱼，武昌鱼，鲇鱼
 // fishsfactor[0]=39;
 if(fir->query("qi")<10||sec->query("qi")<10)
     return notify_fail("小心身体，不要钓鱼钓的连命都丢了！\n");
 if(fir->is_busy()||sec->is_busy())
     return notify_fail("还没换好鱼饵呢！\n");
 fir->start_busy(3);
 sec->start_busy(3);

 firfu=random(fir->query("int")*2);

 for(i=13;i>=5;i--)
   if(firfu>=i*3) break;
 message_vision("只见鱼漂一动，$P忙的一收杆.\n",fir);
 if(i<5){
   call_out("no_fish",4,fir);
 }
 else{
   call_out("one_fish",5,fir,i);
 }
 secfu=random(sec->query("int")*2);

 for(i=13;i>=5;i--)
   if(secfu>=i*3)break;
 message_vision("只见鱼漂一动，$P忙的一收杆.\n",sec);
 if(i<5){
   call_out("no_fish",4,sec);
 }
 else{
   call_out("one_fish",5,sec,i);
 }

 if(secfu>firfu){
    if(sec->query("combat_exp")>10000) {
      return notify_fail("经验已经不少了，所以经验和潜能还是找别处挣吧！\n");
   }


   message_vision("这一回合$P比$p的水平高！所以应该得到奖励！\n\n",sec,fir);
   message_vision("$P得到了"+chinese_number(secfu/3)+"点经验\n",sec);
   comba=sec->query("combat_exp");
   comba+=secfu/3;
   sec->set("combat_exp",comba);
   message_vision("$P得到了"+chinese_number(secfu/5)+"点潜能\n",sec);
   comba=secfu/5;
   comba+=(int) sec->query("potential");
   sec->set("potential",comba );
 }
 if(secfu<firfu){
   if(fir->query("combat_exp")>10000){
     return notify_fail("经验已经不少了，所以经验和潜能还是找别处挣吧！\n");
   }

   message_vision("$P比$p的水平高！所以应该得到奖励！\n\n",fir,sec);
   message_vision("$P得到了"+chinese_number(firfu/4)+"点经验\n",fir);
   comba=fir->query("combat_exp");
   comba+=firfu/4;
   fir->set("combat_exp",comba);
   message_vision("$P得到了"+chinese_number(firfu/6)+"点潜能\n",fir);
   comba=firfu/6;
   comba+=(int) fir->query("potential");
   fir->set("potential",comba );
 }
 if(secfu==firfu)
 message_vision("这一回合$P和$p的水平一样！所以就不必发奖了！\n",fir,sec);
 sec->receive_damage("qi",20);
 fir->receive_damage("qi",20);
 return 1;
}
private void bouns(object fir,object sec)
{
}
private void no_fish(object fir)
{
   message_vision("看来$P没有悟到钓鱼的关键.\n",fir);
   message_vision("$P不但没有钓到鱼，而且连鱼饵都没了.\n",fir);
}
private void one_fish(object fir,int i)
{
  string fishsname;
   if(i==13)fishsname="鲇鱼";
   if(i==12)fishsname="鲫鱼";
   if(i==11)fishsname="罗非鱼";
   if(i==10)fishsname="白昌鱼";
   if(i==9)fishsname="虹鳟鱼";
   if(i==8)fishsname="莲鱼";
   if(i==7)fishsname="草鱼";
   if(i==6)fishsname="武昌鱼";
   if(i==5)fishsname="鲤鱼";

   message_vision("$P钓到了一条"+fishsname+".\n",fir);
   message_vision("$P开始换鱼饵了.\n",fir);
}
