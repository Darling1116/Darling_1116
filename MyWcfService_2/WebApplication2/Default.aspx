<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="Default.aspx.cs" Inherits="WebApplication2._Default" %>
<!DOCTYPE html>

<head runat="server">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <title></title>
</head>
    <body>
        <form id="form1" runat="server">
            <div></div>
                <asp:Label ID="lable2" runat="server" Text="摄氏温度："></asp:Label>
                <asp:TextBox ID="textBox1" runat="server"></asp:TextBox>
                <asp:Button ID="button1" runat="server" OnClick="button1_Click" Text="摄氏转华氏"/>
                <asp:Label ID="label3" runat="server" Text="华氏温度："></asp:Label>
            <p>
                <asp:Label ID="label4" runat="server" Text="华氏温度："></asp:Label>
                <asp:TextBox ID="textBox2" runat="server"></asp:TextBox>
                <asp:Button ID="button2" runat="server" OnClick="button2_Click" Text="华氏转摄氏"/>
                <asp:Label ID="label5" runat="server" Text="摄氏温度："></asp:Label>
            </p>
       </form>
    </body>


