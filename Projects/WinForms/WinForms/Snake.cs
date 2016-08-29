using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WinForms
{
    public partial class Snake : Form // Not part of project
    {

        private List<Circle> Snakey = new List<Circle>();
        private Circle food = new Circle();

        public Snake()
        {
            InitializeComponent();

            new Settings();

            gameTimer.Interval = 1000 / Settings.Speed;
            gameTimer.Tick += UpdateScreen;
            gameTimer.Start();

            StartGame();
        }

        private void StartGame()
        {
            new Settings();

            gameOver.Visible = false;

            Snakey.Clear();
            Circle head = new Circle();
            head.x = 10;
            head.y = 5;
            Snakey.Add(head);

            scoreValue.Text = Settings.Score.ToString();
            GenerateFood();
        }

        private void GenerateFood()
        {
            int maxXPos = sCanvas.Size.Width / Settings.Width;
            int maxYPos = sCanvas.Size.Height / Settings.Height;

            Random random = new Random();
            food = new Circle();
            food.x = random.Next(0, maxXPos);
            food.y = random.Next(0, maxYPos);
        }

        private void UpdateScreen(object sender, EventArgs e)
        {
            if(Settings.GameOver == true)
            {
                if(Input.KeyPressed(Keys.Enter))
                {
                    StartGame();
                }
            }
            else
            {
                if ((Input.KeyPressed(Keys.Right) || Input.KeyPressed(Keys.NumPad6)) && Settings.direction != Direction.Left)
                    Settings.direction = Direction.Right;
                else if ((Input.KeyPressed(Keys.Left) || Input.KeyPressed(Keys.NumPad4)) && Settings.direction != Direction.Right)
                    Settings.direction = Direction.Left;
                else if ((Input.KeyPressed(Keys.Up) || Input.KeyPressed(Keys.NumPad8)) && Settings.direction != Direction.Down)
                    Settings.direction = Direction.Up;
                else if ((Input.KeyPressed(Keys.Down) || Input.KeyPressed(Keys.NumPad5)) && Settings.direction != Direction.Up)
                    Settings.direction = Direction.Down;

                MovePlayer();
            }

            sCanvas.Invalidate();
        }



        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void sCanvas_Paint(object sender, PaintEventArgs e)
        {
            Graphics canvas = e.Graphics;
            
            if(!Settings.GameOver)
            {
                Brush snakeColour;

                for(int i = 0; i<Snakey.Count; ++i)
                {
                    if (i == 0)
                        snakeColour = Brushes.Aquamarine;
                    else
                        snakeColour = Brushes.Beige;

                    canvas.FillEllipse(snakeColour,
                        new Rectangle(Snakey[i].x * Settings.Width,
                                        Snakey[i].y * Settings.Height,
                                        Settings.Width, Settings.Height));

                    canvas.FillEllipse(Brushes.MediumVioletRed,
                        new Rectangle(food.x * Settings.Width,
                                        food.y * Settings.Height,
                                        Settings.Width, Settings.Height));
                }
            }
            else
            {
                string gameOverText = "Game over \nYour finale score is: " + Settings.Score + "\nPress Enter to try again";
                gameOver.Text = gameOverText;
                gameOver.Visible = true;
            }
        }

        private void MovePlayer()
        {
            for (int i = Snakey.Count - 1; i >= 0; --i)
            {
                if (i == 0)
                {
                    switch (Settings.direction)
                    {
                        case Direction.Right:
                            Snakey[i].x++;
                            break;
                        case Direction.Left:
                            Snakey[i].x--;
                            break;
                        case Direction.Up:
                            Snakey[i].y--;
                            break;
                        case Direction.Down:
                            Snakey[i].y++;
                            break;
                    }

                    int maxXPos = sCanvas.Size.Width / Settings.Width;
                    int maxYPos = sCanvas.Size.Height / Settings.Height;

                    //if (Snakey[i].x <0 || Snakey[i].y < 0||Snakey[i].x > maxXPos||Snakey[i].y > maxYPos)
                    //{
                    //    Die();
                    //}

                    if (Snakey[i].x < 0)
                        Snakey[i].x += maxXPos + 1;
                    else if (Snakey[i].x > maxXPos)
                        Snakey[i].x -= maxXPos - 1;
                    else if (Snakey[i].y < 0)
                        Snakey[i].y += maxYPos + 1;
                    else if (Snakey[i].y > maxYPos)
                        Snakey[i].y -= maxYPos - 1;

                    for (int j = 1; j < Snakey.Count; ++j)
                    {
                        if (Snakey[j].x == Snakey[0].x && Snakey[j].y == Snakey[0].y)
                            Die();
                    }

                    if (food.x == Snakey[0].x && food.y == Snakey[0].y)
                        Eat();
                }
                else
                {
                    Snakey[i].x = Snakey[i - 1].x;
                    Snakey[i].y = Snakey[i - 1].y;
                }              
            }
        }

        private void Die()
        {
            Settings.GameOver = true;
        }

        private void Eat()
        {
            Circle food = new Circle();
            food.x = Snakey[Snakey.Count - 1].x;
            food.y = Snakey[Snakey.Count - 1].y;

            Snakey.Add(food);

            GenerateFood();

            Settings.Score += Settings.Points;
            scoreValue.Text = Settings.Score.ToString();


        }

        private void Snake_KeyDown(object sender, KeyEventArgs e)
        {
            Input.ChangeState(e.KeyCode, true);
        }

        private void Snake_KeyUp(object sender, KeyEventArgs e)
        {
            Input.ChangeState(e.KeyCode, false);
        }

        private void Snake_KeyPress(object sender, KeyPressEventArgs e)
        {
            
        }

        private void label1_Click_1(object sender, EventArgs e)
        {

        }
    }
}
