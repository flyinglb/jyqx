// message.c
// modified by wind
//varargs void message_vision(string msg, object me, object you)
varargs void message_vision(string msg, object me, object you,string type)
{
        string my_gender, your_gender, my_name, your_name;
        string str1, str2, str3;
// �����ֳ�ת�� start
	int userno;
	object *player;
// �����ֳ�ת�� end

        my_name= me->name();
        my_gender = me->query("gender");
        str1 = replace_string(msg,  "$P", gender_self(my_gender));
        str1 = replace_string(str1, "$N", gender_self(my_gender));
        str3 = replace_string(msg,  "$P", my_name);
        str3 = replace_string(str3, "$N", my_name);
        if( you ) {
                your_name= you->name();
                your_gender= you->query("gender");
                str2 = replace_string(msg,  "$P", gender_pronoun(my_gender));
                str2 = replace_string(str2, "$p", gender_self(your_gender));
                str2 = replace_string(str2, "$N", my_name);
                str2 = replace_string(str2, "$n", gender_self(your_gender));
                if(type == "fight" && you->query("env/no_fight_msg"));
                else message("vision", str2, you);
                //message("vision", str2, you);
                str1 = replace_string(str1, "$p", gender_pronoun(your_gender));
                str1 = replace_string(str1, "$n", your_name);
                str3 = replace_string(str3, "$p", your_name);
                str3 = replace_string(str3, "$n", your_name);
        }
        if(type == "fight" && me->query("env/no_fight_msg"));
        else message("vision", str1, me);
        //message("vision", str1, me);
        message("vision", str3,  environment(me), ({ me, you}) );
// �����ֳ�ת�� start
	if ((string)environment(me)->query("short") == "��̨")
	for (userno=0; userno<sizeof(player); userno++)
	    if ((player[userno])->query_temp("view_leitai") &&
	        (player[userno]) != me &&
	        (player[userno]) != you) 
	       tell_object(player[userno], str3);
// �����ֳ�ת�� end
}

void tell_object(object ob, string str)
{
        message("tell_object", str, ob);
}

varargs void tell_room(mixed ob, string str, object *exclude)
{
        if( ob ) message("tell_room", str, ob, exclude);
}

void shout(string str)
{
        message("shout", str, users(), this_player());
}

void write(string str)
{
        str = CONVERT_D->output(str,this_player());
        if( this_player() )
                message("write", str, this_player());
        else if( previous_object() )
                message("write", str, previous_object());
        else
                efun::write(str);
}

varargs void say(string str, mixed exclude)
{
        if( living(previous_object()) )
                message("say", str, environment(previous_object()), previous_object());
        else if( this_player() )
                message("say", str, environment(this_player()), this_player());
}

/*
varargs void printf (string msg, mixed a1, mixed a2, mixed a3, mixed a4,
         mixed a5, mixed a6, mixed a7, mixed a8, mixed a9, mixed a10,
         mixed a11, mixed a12, mixed a13, mixed a14, mixed a15, mixed a16)
{
    msg = sprintf (msg,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16); 
    write (msg);
}
*/

int notify_fail (mixed arg)
{
    if (stringp(arg))
        arg = (string) CONVERT_D->output(arg,this_player());
    return efun::notify_fail (arg);
}
