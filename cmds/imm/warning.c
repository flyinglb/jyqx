      //warning.c 警告犯错玩家
// Byp@MX

inherit F_CLEAN_UP;

int main(object me, string arg)
{
        object who;
        string bec;
//      if(!wizardp(me))
//              return notify_fail("你想干什么？\n");
                
        if( !arg || sscanf(arg, "%s because %s", arg, bec)!=2 )
                return notify_fail("指令格式：warning <id> because <原因>\n");
        
        who = find_player(arg);
        
        if(!who) 
                return notify_fail("没有这个玩家。\n");
                
        if(wizardp(who)) //可以改成高级巫师对下级警告
                return notify_fail("警告巫师？\n");
        if(who->query_temp("cmds_warning_const") > 0) {
                shout(HIR+ who->name() + HIR + "因为 " + bec + " 被严重警告！\n"NOR);
                write(HIR+ who->name() + HIR + "因为 " + bec + " 被严重警告！\n"NOR);
        } else {
                shout(HIR+ who->name() + HIR + "因为 " + bec + " 被警告一次！\n"NOR);
                write(HIR+ who->name() + HIR + "因为 " + bec + " 被警告一次！\n"NOR);
        }        
        who->add_temp("cmds_warning_const", 1);
        return 1;
}
