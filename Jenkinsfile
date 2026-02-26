pipeline {
    agent any

    stages {

        stage('Build Backend') {
            steps {
                sh 'docker build -t backend-app backend'
            }
        }

        stage('Run Backends') {
            steps {
                sh '''
                docker rm -f backend1 backend2 nginx-lb || true
                docker network create lab6-network || true

                docker run -d --name backend1 --network lab6-network backend-app
                docker run -d --name backend2 --network lab6-network backend-app
                '''
            }
        }

        stage('Run NGINX') {
            steps {
                sh '''
                docker run -d --name nginx-lb \
                --network lab6-network \
                -p 80:80 \
                -v $(pwd)/nginx/default.conf:/etc/nginx/conf.d/default.conf \
                nginx
                '''
            }
        }
    }
}
